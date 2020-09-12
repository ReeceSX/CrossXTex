/***
    Copyright (©) 2020 Reece Wilson (a/k/a "Reece"). All rights reserved.
    Do not use, copy, distribute, publish, disseminate, modify, or sublicense without express permission from the rights holder[s]. 
    Please do no evil.
 
    File: StdFS.hpp
    Date: 2020-9-12
    Author: Reece
    Purpose: TBD
***/
#pragma once

template<typename T>
class ScopedFile
{
public:

    ScopedFile(const std::string & path, bool reset = false)
    {
        Init(path, reset);
    }

    ScopedFile(const std::wstring & path, bool reset = false)
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
        Init(converter.to_bytes(path), reset);
    }

    ~ScopedFile()
    {
        _stream.close();

        if (this->_temp)
        {
            std::filesystem::remove(_path);
        }
    }
    

    void MakeTemp()
    {
        this->_temp = false;
    }

protected:

    T _stream;
    std::string _path;
private:


    void Init(const std::string & path, bool reset)
    {
        this->_path = path;
        this->_temp = false;

        if (reset)
        {
            _stream.open(path, std::ios::trunc);
            _stream.close();
        }

        _stream.open(path, std::ios::binary);
    }


    bool _temp;
};

class ScopedWriteFile : public ScopedFile<std::ofstream>
{
public:

    ScopedWriteFile(const std::string & name, bool reset = false) : ScopedFile(name, reset)
    {
        // -
    }

    ScopedWriteFile(const std::wstring & name, bool reset = false) : ScopedFile(name, reset)
    {
        // -
    }

    void SeekBegin(size_t offset) 
    {
        _stream.seekp(offset, std::ios_base::beg);
    }

    size_t GetOffset() 
    {
        return static_cast<size_t>(_stream.tellp());;
    }

    size_t GetLength()
    {
        if (!_stream.is_open())
        {
            return 0;
        }
        auto old = _stream.tellp();
        _stream.seekp(0, std::ios_base::end);
        auto ret = GetOffset();
        _stream.seekp(old, std::ios_base::beg);
        return ret;
    }

    bool Write(const void * in, size_t length)
    {
        if (!_stream.is_open())
        {
            return false;
        }
        if (!_stream.write(reinterpret_cast<const char *>(in), length))
        {
            MakeTemp();
            return false;
        }
        return true;
    }
};


class ScopedReadFile : public ScopedFile<std::ifstream>
{
public:

    ScopedReadFile(const std::string & name) : ScopedFile(name, false)
    {
        // -
    }

    ScopedReadFile(const std::wstring & name) : ScopedFile(name, false)
    {
        // -
    }

    void SeekBegin(size_t offset)
    {
        _stream.seekg(offset, std::ios_base::beg);
    }

    void SeekEnd(size_t offset)
    {
        _stream.seekg(offset, std::ios_base::end);
    }


    size_t GetOffset()
    {
        return static_cast<size_t>(_stream.tellg());;
    }

    size_t GetLength()
    {
        if (!_stream.is_open())
        {
            return 0;
        }
        auto old = _stream.tellg();
        _stream.seekg(0, std::ios_base::end);
        auto ret = GetOffset();
        _stream.seekg(old, std::ios_base::beg);
        return ret;
    }

    size_t Read(void * in, size_t length)
    {
        if (!_stream.is_open())
        {
            return false;
        }
        return _stream.read(reinterpret_cast<char *>(in), length) ? length : _stream.gcount();
    }
    
    size_t Read(size_t length)
    {
        std::vector<uint8_t> in;
        in.resize(length);
        return Read(in.data(), length);
    }
};
