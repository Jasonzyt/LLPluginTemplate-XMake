# LiteLoaderBDS Plugin Template for XMake

[XMake](https://xmake.io) is a lightweight cross-platform build utility based on Lua. It is very easy to use.  
What's more, it has modern C/C++ build tools, powerful dependency package integration.  
Instead of the traditional `cmake` or `make`, it is more suitable for the development of small and medium-sized projects.  
So I strongly recommend you to have a try!  

## Usage

With IDE: Visual Studio Code

### 0x0 Set Up Environment

#### 0x00 Install MSVC Toolchain & Windows SDK

MSVC Toolchain is required to build LiteLoaderBDS plugin.  

I suggest using Visual Studio Installer to install it so that you don't need to browse the web for the download links.
And Visual Studio 2022 is also a powerful IDE & debugger. You might use it for debugging in the future.  

Download Visual Studio Installer [here](https://visualstudio.microsoft.com/downloads/).
(You can install Visual Studio Code at the same page. We will use it later.)

Then, install the installer. (This might heard a little bit weird xD.)
Wait for the installation to complete.  

Open Visual Studio Installer. Install Visual Studio 2022 IDE and select `Desktop development with C++` workload.   
![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/12584dbb-e69c-46a9-aa86-ef3d22774591)  
At last, click `Install`.  

> By the way, if you want to use [vcpkg](https://github.com/microsoft/vcpkg), you must install the English language pack.
>

#### 0x01 Install XMake

Download XMake installer for windows-x64 from [release](https://github.com/xmake-io/xmake/releases/latest) page.  
Then double-click to install it.  

#### 0x02 Install Git

Git is a distributed version control system. We will use it to manage our project and host it on GitHub.

Download Git from [here](https://git-scm.com/downloads) and install it.

#### 0x02 Install Visual Studio Code and Extensions

First, let me explain why I suggest VSCode instead of CLion or VS2022.

VS2022 is bound with MSBuild or CMake and CLion is bound with CMake or Make.
They don't have a highly-custom interface for non-mainstream build tools.
If you use CLion to develop LiteLoaderBDS plugin, you will have to generate CMakeLists.txt(XMake provided this feature!) every time you add new files or modify the build script.  

VSCode is a lightweight IDE. It has a highly-custom interface for build tools.  

Download VSCode from [here](https://code.visualstudio.com/) and install it.  
Then, install `XMake` extension and `C/C++ Extension Pack` in Marketplace(Ctrl+Shift+X to open it. it's on sidebar).
![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/ca59f627-9aba-4d77-88e5-9809fd1ea93c)

Well done! You have set up the environment for LiteLoaderBDS plugin development.

### 0x1 Create Your Project Using This Template

Scroll up to the top of this page. Click `Use this template` button.
![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/a10a89a0-61a1-4cc3-a6f6-11961f742f54)
    
Then, fill in the form and click `Create repository from template`.

> Choose `Private` if you don't want to share your code with others.
>

Copy the URL of your project.

Open terminal and cd to a directory you want to put your project in.  
Then, run the following command to clone your project.

```bash
git clone <URL> --recursive
```
> Use `--recursive` option to clone the LiteLoaderBDS submodule.
>

### 0x2 Name Your Project

Run `NameYourProject.exe` to name your project.
You can delete this executable after naming your project.

### 0x3 Build Your Project

Build with XMake is very simple, just run `xmake build` in the root directory of your project.
An after-build script is provided. It will copy the built plugin to `release/` and rename it.
You can modify `xmake.lua` to do more things. [Here](https://xmake.io/#/getting_started) is the official guide.

### 0x4 Run BDS

Put the built dlls from `build/windows/x64/release` or `release/` into `plugins/` folder of your BDS installation directory.
Then, run `bedrock_server_mod.exe` to start your server.

## License

[MIT](LICENSE)

## Aknowledgements

- [XMake](https://xmake.io)
- [LiteLoaderBDS](https://github.com/LiteLDev/LiteLoaderBDS)