[English](#LiteLoaderBDS-Plugin-Template-for-XMake) | [中文](#LiteLoaderBDS-插件模板使用XMake--C)

![CC0](https://licensebuttons.net/l/zero/1.0/88x31.png)

---

# LiteLoaderBDS Plugin Template for XMake

[XMake](https://xmake.io) is a lightweight cross-platform build utility based on Lua. It is very easy to use.

What's more, it has modern C/C++ build tools, powerful dependency package integration.

Instead of the traditional `cmake` or `make`, it is more suitable for the development of small and medium-sized projects.
(You can even use XMake to generate CMakeLists.)

So I strongly recommend you to have a try!

> Though the official name is xmake, I prefer to call it XMake to follow UpperCamel case.
>

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
> Use `--recursive` option to clone the LiteLoaderBDS SDK submodule.
>

### 0x2 Name Your Project

Run `NameYourProject.exe` to name your project.
You can delete this executable after naming your project.

### 0x3 Build Your Project

Build with XMake is very simple, just run `xmake build` in the root directory of your project.

An after-build script is provided. It will copy the built plugin to `release/` and rename it.
You can modify `xmake.lua` to do more things like copying the dlls to BDS path.

[Here](https://xmake.io/#/getting_started) is the official guide.

When build for the first time or the SDK updated, it will ask you to select a pdb file to generate bedrock_server_api.lib and bedrock_server_var.lib.

### 0x4 Run BDS

Put the built dlls from `build/windows/x64/release` or `release/` into `plugins/` folder of your BDS installation directory.
Then, run `bedrock_server_mod.exe` to start your server.

### 0x5 Update SDK

Run `script/UpdateSDK.cmd` to update SDK.
```bash
# At the root directory of your project
script/UpdateSDK.cmd
```

## License

Licensed under [CC0](LICENSE)

## Aknowledgements

- [XMake](https://xmake.io)
- [LiteLoaderBDS](https://github.com/LiteLDev/LiteLoaderBDS)

---

[English](#LiteLoaderBDS-Plugin-Template-for-XMake) | [中文](#LiteLoaderBDS-插件模板使用XMake--C)

---

# LiteLoaderBDS 插件模板(使用XMake & C++)

[XMake](https://xmake.io/#/zh-cn/) 是一个基于 Lua 的轻量级跨平台构建工具，它非常易于使用。

更重要的是，它具有现代 C/C++ 构建工具，强大的依赖包集成，与传统 `cmake` 或 `make` 不同，它更适合中小型项目的开发。(你甚至可以用XMake来生成CMakeLists)

所以我强烈推荐你试一试！

## 使用方法

IDE: Visual Studio Code

### 0x0 环境搭建

#### 0x00 安装 MSVC 工具链 & Windows SDK

构建 LiteLoaderBDS 插件需要 MSVC 工具链。

我建议使用 Visual Studio Installer 来安装它，这样你就不需要在网上寻找下载链接了。

Visual Studio 2022 是一个强大的 IDE 和调试器，你以后可能会用它来调试。

下载 Visual Studio Installer [here](https://visualstudio.microsoft.com/downloads/)。

然后安装这个安装器。(这听起来可能有点奇怪 xD.)

等待安装完成。

打开 Visual Studio Installer。安装 Visual Studio 2022 IDE 并选择 `使用C++的桌面开发`。

![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/12584dbb-e69c-46a9-aa86-ef3d22774591)

最后，点击 `安装`。

> 顺便说一句，如果你想使用 [vcpkg](https://github.com/microsoft/vcpkg)，你必须安装英文语言包。

#### 0x01 安装 XMake

从 [release](https://github.com/xmake-io/xmake/releases/latest) 页面下载 Windows-x64 版本的 XMake 安装器。

然后双击安装它。

#### 0x02 安装 Git

Git 是一个分布式版本控制系统。我们将使用它来管理我们的项目并将其托管在 GitHub 上。

从 [这里](https://git-scm.com/downloads) 下载 Git 并安装它。

#### 0x02 安装 Visual Studio Code 和扩展

首先，让我解释一下为什么我建议使用 VSCode 而不是 CLion 或 VS2022。

VS2022 绑定了 MSBuild 或 CMake，CLion 绑定了 CMake 或 Make。

它们没有一个高度自定义的界面来支持非主流的构建工具。

如果你使用 CLion 来开发 LiteLoaderBDS 插件，你将不得不每次添加新文件或修改构建脚本时都要生成 CMakeLists.txt(XMake 提供了这个功能！)。

VSCode 是一个轻量级的 IDE。它有一个高度自定义的接口来支持构建工具。

从 [这里](https://code.visualstudio.com/) 下载 VSCode 并安装它。

然后，在扩展市场中安装 `XMake` 扩展和 `C/C++ Extension Pack` 扩展(Ctrl+Shift+X 打开扩展市场，它在侧边栏上)。

![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/ca59f627-9aba-4d77-88e5-9809fd1ea93c)

### 0x1 使用这个模板创建你的项目

滚动到本页顶部。点击 `Use this template` 按钮。

![image](https://github.com/Jasonzyt/LLPluginTemplate-XMake/assets/66063199/a10a89a0-61a1-4cc3-a6f6-11961f742f54)

然后，填写表单并点击 `Create repository from template`。

> 如果你不想与他人分享你的代码，请选择 `Private`。

复制你的项目的 URL。

打开终端并 cd 到你想要放置你的项目的目录。

然后，运行以下命令来clone你的项目至本地。

```bash
git clone <URL> --recursive
```

> 使用 `--recursive` 选项来克隆 LiteLoaderBDS SDK 子模块。

### 0x2 给你的项目命名

运行 `NameYourProject.exe` 来给你的项目命名。
你可以在命名后删除这个可执行文件。

### 0x3 构建你的项目

使用 XMake 构建非常简单，只需在你的项目的根目录运行 `xmake build`。

本模板提供了一个 after-build 脚本，它会自动将构建好的插件dll复制到 `release/` 目录并按照版本号重命名。
你可以修改 `xmake.lua` 来自定义构建逻辑，例如，你可以将构建好的插件dll复制到你的 BDS 服务器目录。

关于 XMake 的详细接口文档和使用教程在 [这里](https://xmake.io/#/zh-cn/getting_started)

### 0x4 运行BDS

把构建好的插件dll从 `build/windows/x64/release` 或 `release/` 复制到你的 BDS 安装目录的 `plugins/` 文件夹。
然后，运行 `bedrock_server_mod.exe` 来启动你的服务器。

### 0x5 更新SDK

运行 `script/UpdateSDK.cmd` 来更新 LiteLoaderBDS SDK。
```bash
# At the root directory of your project
script/UpdateSDK.cmd
```

## 开源许可证

本项目使用 [CC0](LICENSE) 许可证。

## 致谢

- [XMake](https://xmake.io)
- [LiteLoaderBDS](https://github.com/LiteLDev/LiteLoaderBDS)
