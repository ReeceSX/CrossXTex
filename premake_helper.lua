function genProject(path)

	local projectFiles = {
		path .. "/DirectXTex/BC.h",
		path .. "/DirectXTex/BCDirectCompute.h",
		path .. "/DirectXTex/DDS.h",
		path .. "/DirectXTex/DirectXTex.h",
		path .. "/DirectXTex/DirectXTexP.h",
		path .. "/DirectXTex/filters.h",
		path .. "/DirectXTex/scoped.h",
		
		path .. "/DirectXTex/BC.cpp",
		path .. "/DirectXTex/BC4BC5.cpp",
		path .. "/DirectXTex/BC6HBC7.cpp",
		
		path .. "/DirectXTex/DirectXTexConvert.cpp",
		path .. "/DirectXTex/DirectXTexDDS.cpp",
		path .. "/DirectXTex/DirectXTexFlipRotate.cpp",
		path .. "/DirectXTex/DirectXTexHDR.cpp",
		path .. "/DirectXTex/DirectXTexImage.cpp",
		path .. "/DirectXTex/DirectXTexMipmaps.cpp",
		path .. "/DirectXTex/DirectXTexMisc.cpp",
		path .. "/DirectXTex/DirectXTexNormalMaps.cpp",
		path .. "/DirectXTex/DirectXTexPMAlpha.cpp",
		path .. "/DirectXTex/DirectXTexResize.cpp",
		path .. "/DirectXTex/DirectXTexTGA.cpp",
		path .. "/DirectXTex/DirectXTexUtil.cpp"
	}
		
		
	if (_G.win32) then
		table.insert(projectFiles, path .. "/DirectXTex/DirectXTexCompressGPU.cpp")
		table.insert(projectFiles, path .. "/DirectXTex/BCDirectCompute.cpp")
		table.insert(projectFiles, path .. "/DirectXTex/DirectXTexWIC.cpp")
		-- TODO: if d3d11
		table.insert(projectFiles, path .. "/DirectXTex/DirectXTexD3D12.cpp")
		table.insert(projectFiles, path .. "/DirectXTex/d3dx12.h")
	else
		table.insert(projectFiles, path .. "/DirectXTex/DirectXTexCompress.cpp")
	end
	
	local cmd = "\"" .. path .. "\\DirectXTex\\Shaders\\CompileShaders.cmd\" " .. "\"" .. path .. "\\DirectXTex\\Shaders";
	print("fxc compile script", cmd)

	if (_G.win32) then
		buildcommands { cmd }
	end
	
	defines 
	{
		"_WIN32_WINNT=0x0A00",

	}
	
	if (not _G.win32) then
		defines {"_DXTX_NOWIN"}
	end 

	files 
	{
		projectFiles
	}
	
	includedirs 
	{
		path .. "/DirectXTex",
		path .. "/DirectXMath",
		path .. "/PlatformSupport"
	}

end

return genProject
