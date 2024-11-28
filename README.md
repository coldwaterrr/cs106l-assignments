# CS106L 作业

这个仓库包含了斯坦福大学 CS106L 课程的起始代码，这是一个关于标准 C++ 编程的课程。

## 开始之前

在开始之前，有一些先决条件：

* 你需要在你的电脑上安装 [Python 3.8](https://www.python.org/downloads/) 或更高版本。你可以通过在终端中运行 `python3 --version`（在 Windows 上运行 `python --version`）来检查。
* 你需要一个可以编写代码的 IDE。我们鼓励你在这门课中使用 VSCode（[参见下面的指南](#vscode-setup-instructions)），但你可以使用任何你能舒适地编写和编译 C++ 代码的 IDE。
* 你需要 [Git](https://git-scm.com/)。如果你使用 VSCode，你应该已经有了这个工具。你可以通过在终端中运行 `git --version` 来检查。

接下来，下载起始代码。打开一个终端（如果你使用 VSCode，按 <kbd>Ctrl+\`</kbd> 或者在顶部选择 **Terminal > New Terminal**）并运行以下命令：

```sh
git clone https://github.com/cs106l/cs106l-assignments.git
```

这将会把起始代码下载到一个名为 `cs106l-assignments` 的文件夹中。如果你使用 VSCode，你可以然后打开一个专门用于 CS106L 的 VSCode 工作区：

```sh
cd cs106l-assignments && code .
```

然后你就可以开始了！

### 获取作业

当我们更新现有作业并发布新作业时，我们会将更新推送到这个仓库。要获取新作业，请打开一个终端到你的 `cs106l-assignments` 目录并运行

```sh
git pull origin main
```

你现在应该有最新的起始代码了！

## VSCode 设置说明

我们推荐使用 VSCode 来编写这门课的 C++ 代码。请参见下面的说明来为你的机器设置 VSCode/GCC。

### Mac

#### 第一步：安装 VSCode

访问 [这个链接](https://code.visualstudio.com/docs/setup/mac) 并下载适用于 Mac 的 Visual Studio Code。按照该网页下 **Installation** 部分的说明进行操作。

在 VSCode 中，前往扩展标签 <img src="docs/vscode-extensions.png" display="inline" height="20px"></img> 并搜索 **C/C++**。点击 **C/C++** 扩展，然后点击 **Install**。

<b> 🥳 此时你应该已经成功在你的 Mac 上安装了 VSCode 👏 </b>

#### 第二步：安装 C++ 编译器

<ol>
  <li>
    通过运行以下命令检查你是否有 Homebrew
    <pre lang="sh">brew --version</pre>
    如果你得到类似
    <pre lang="sh">
brew --version
Homebrew 4.2.21</pre>
    的输出，那么 <b>跳过第 2 步并进入第 3 步。</b> 如果你得到其他看起来可疑的输出，请继续第 2 步！
  </li>
  <li>
    运行以下命令：
    <pre lang="sh">/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</pre>
    这将会下载 Homebrew🍺，这是一个包管理器。Woot woot。
  </li>
  <li>
    运行以下命令：
    <pre lang="sh">brew install gcc</pre>
    这将会安装编译器（GCC）。
  </li>
  <li>
    记下 Homebrew 安装的 GCC 版本。在大多数情况下，这将是 <code>g++-14</code>。默认情况下，Mac 上的 <code>g++</code> 命令是内置 <code>clang</code> 编译器的别名。我们可以通过运行 <pre lang="sh">echo 'alias g++="g++-14"' >> ~/.zshrc</pre> 来修复这个问题，使 <code>g++</code> 指向我们刚刚安装的 GCC 版本。在上述命令中将 <code>g++-14</code> 更改为你安装的 GCC 版本。
  <li>
    重启你的终端并通过运行以下命令验证一切是否正常：
    <pre lang="sh">g++ --version</pre>
  </li>
</ol>

### Linux

这些说明适用于基于 Debian 的发行版，如 Ubuntu。在 Ubuntu 20.04 LTS 上测试。

#### 第一步：安装 VSCode

访问 [这个链接](https://code.visualstudio.com/docs/setup/linux) 并下载适用于 Linux 的 Visual Studio Code。按照该网页下 **Installation** 部分的说明进行操作。

在 VSCode 中，前往扩展标签 <img src="docs/vscode-extensions.png" display="inline" height="20px"></img> 并搜索 **C/C++**。点击 **C/C++** 扩展，然后点击 **Install**。

<b> 🥳 此时你应该已经成功在你的 Linux 机器上安装了 VSCode 👏 </b>

#### 第二步：安装 C++ 编译器

<ol>
  <li>在终端中，通过运行以下命令更新 Ubuntu 包列表 <pre lang="sh">sudo apt-get update</pre></li>
  <li>接下来安装 G++ 编译器： <pre lang="sh">sudo apt-get install g++-10</pre></li>
  <li>默认情况下，将使用系统版本的 G++。要将其更改为你刚刚安装的版本，你可以配置 Linux 使用 G++ 版本 10 或更高版本，如下所示： <pre lang="sh">sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-10 10</pre></li>
  <li>重启你的终端并验证 GCC 是否正确安装。你必须有 10 或更高版本的 GCC： <pre lang="sh">g++ --version</pre></li>
</ol>

### Windows

#### 第一步：安装 VSCode

访问 [这个链接](https://code.visualstudio.com/docs/setup/windows) 并下载适用于 Windows 的 Visual Studio Code。按照该网页下 **Installation** 部分的说明进行操作。

在 VSCode 中，前往扩展标签 <img src="docs/vscode-extensions.png" display="inline" height="20px"></img> 并搜索 **C/C++**。点击 **C/C++** 扩展，然后点击 **Install**。

<b> 🥳 此时你应该已经成功在你的 PC 上安装了 VSCode 👏 </b>

#### 第二步：安装 C++ 编译器

1. 按照 [这个链接](https://code.visualstudio.com/docs/cpp/config-mingw) 的说明进行操作
    * 你应该按照 **Installing the MinGW-w64 toolchain** 部分的说明进行操作。

2. 完全按照 **Installing the MinGW-w64 toolchain** 部分的说明操作后，你现在应该可以通过运行以下命令验证一切是否正常：

```sh
g++ --version
```
