# 作业 1：SimpleEnroll

截止日期：10月11日星期五晚上11:59

## 概述

又到了这个季度的时间了；是时候使用 SimpleEnroll 了 🤗 Wootwoot。
每个斯坦福学生在他们的职业生涯中都会意识到，他们最终必须毕业——因此选课成为了一种战略性努力，以最大化毕业所需的经验值，同时还能保证每晚睡眠超过4小时！

在这个希望很短的作业中，我们将使用 ExploreCourses API 的数据来确定 ExploreCourses 上哪些 CS 课程在今年开设，哪些没有！我们将利用流，同时在 C++ 中练习初始化和引用。让我们开始吧 ʕ•́ᴥ•̀ʔっ

你只需要关心两个文件：

* `main.cpp`：所有代码都在这里 😀！
* `utils.cpp`：包含一些实用函数。你将使用此文件中定义的函数，但不需要修改它。

要下载此作业的起始代码，请参阅课程作业库中的[**入门指南**](../README.md#getting-started)中的说明。

## 运行你的代码

要运行你的代码，首先需要编译它。打开终端（如果你使用 VSCode，按 <kbd>Ctrl+\`</kbd> 或者在顶部选择 **Terminal > New Terminal**）。然后确保你在 `assign1/` 目录下并运行：

```sh
g++ -std=c++20 main.cpp -o main
```

假设你的代码编译没有任何编译错误，现在可以运行：

```sh
./main
```

这将实际运行 `main.cpp` 中的 `main` 函数。这将执行你的代码，然后运行一个自动评分器来检查你的代码是否正确。

在按照以下说明操作时，我们建议间歇性地使用自动评分器进行编译/测试，以确保你走在正确的轨道上！

> [!NOTE]  
> ### Windows 用户注意
> 在 Windows 上，你可能需要使用以下命令编译代码：
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp -o main
> ```
> 以便看到输出。此外，输出的可执行文件可能被称为 `main.exe`，在这种情况下你将使用以下命令运行代码：
> ```sh
> ./main.exe
> ```

## 第 0 部分：阅读代码并填写 `Course` 结构体

1. 在这个作业中，我们将使用 `Course` 结构体来表示从 ExploreCourses 中提取的记录。查看 `main.cpp` 中 `Course` 结构体的（不完整）定义并填写字段定义。最终，我们将使用流来生成 `Course` —— 记住流处理的类型是什么？

2. 查看 `main.cpp` 中的 `main` 函数，特别注意 `courses` 如何传递给 `parse_csv`、`write_courses_offered` 和 `write_courses_not_offered`。想想这些函数在做什么。你需要更改函数定义中的任何内容吗？剧透一下，你需要。

## 第 1 部分：`parse_csv`

查看 `courses.csv`，它是一个 CSV 文件，包含三列：标题、学分数和季度。实现 `parse_csv`，使其为 CSV 文件中的每一行创建一个包含该行标题、学分数和季度的 `Course` 结构体。

你需要考虑的几件事：
1. 你将如何读取 `courses.csv`？哈哈哈，也许是一个流 😏？
2. 你将如何获取文件中的每一行？

### 提示

1. 查看我们在 `utils.cpp` 中提供的 `split` 函数。它可能会派上用场！
    * 随时查看 `split` 的实现并向我们提问——你应该能够推理它，因为它使用了 `stringstream`。
2. 每一**行**都是一条记录！*这很重要，所以我们再说一遍 :>)*
3. 在 CSV 文件中（特别是在 `courses.csv` 中），第一行通常是定义列名的行（列标题行）。这行实际上并不对应于 `Course`，所以你需要以某种方式跳过它！

## 第 2 部分：`write_courses_offered`

好的。现在你有一个填充了所有 `courses.csv` 文件记录的 `courses` 向量，这些记录都整齐地存储在 `Course` 结构体中！你对只对开设的课程感兴趣，对吧？**如果课程的季度字段不是字符串 `“null”`，则该课程被视为开设。** 在这个函数中，将所有季度字段中没有 `“null”` 的课程写入 `“student_output/courses_offered.csv”`。

> [!IMPORTANT]  
> 写入 CSV 文件时，请遵循以下格式：
> ```
> <Title>,<Number of Units>,<Quarter>
> ```
> 注意逗号之间**没有空格**！如果不遵循此格式，自动评分器将不高兴！
>
> 另外，**请确保将列标题行写为输出的第一行**。这与前一步中你必须跳过的 `courses.csv` 中的行相同！

一旦调用了 `write_courses_offered`，我们期望所有开设的课程（因此你写入输出文件的所有课程）将从 `all_courses` 向量中删除。**这意味着在此函数运行后，`all_courses` 应仅包含未开设的课程！**

一种方法是使用另一个向量跟踪开设的课程，并从 `all_courses` 中删除它们。就像在 Python 和许多其他语言中一样，在迭代数据结构时删除元素是个坏主意，所以你可能希望在写入所有开设的课程到文件后再这样做。

## 第 3 部分：`write_courses_not_offered`

所以你对未开设的课程感兴趣... 在 `write_courses_not_offered` 函数中，将 `unlisted_courses` 中的课程写入 `“student_output/courses_not_offered.csv”`。记住，由于你在上一步中删除了开设的课程，`unlisted_courses` 仅包含未开设的课程——幸运的你。因此，这一步应该看起来非常类似于第 2 部分，只是更短且稍微简单一点。

## 🚀 提交说明

编译并运行后，如果你的自动评分器看起来像这样：

![显示自动评分器运行且所有测试通过的终端窗口的图像](docs/autograder.png)

那么你已经完成了作业！Woot woot。要提交作业，请完成[此链接](https://forms.gle/UfSDVYpbg472ZXkJ8)上的反馈表单。提交表单后，表单提交确认中将显示提交页面的链接。
