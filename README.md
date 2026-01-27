# Visual Studio Report

<h2>Problem description</h2>

Visual Studio 2022 does not provide a deprecation warning for initialized declarations in `C` projects with the platform toolset v143.

`main.c`
```c
1.  static __declspec(deprecated) int func()
2.  {
3.      return 0;
4.  }
5.
6.  int main()
7.  {
8.      // 1) Deprecation warning.
9.      func();
10.
11.     // 2) Deprecation warning.
12.     int a;
13.     a = func();
14.
15.     // 3) No deprecation warning.
16.     int b = func();
17.
18.     return 0;
19. }
```

`Error List`

![alt text](https://github.com/deniskovalchuk/bug-report-vs-deprecation-warning/blob/ceab5d05b5345a7c7c885cb4968c6973d3f35795/Images/PlatformToolset_v143.png)

This looks like a regression relative to the platform toolset v142, where the warning works as expected:

![alt text](https://github.com/deniskovalchuk/bug-report-vs-deprecation-warning/blob/ceab5d05b5345a7c7c885cb4968c6973d3f35795/Images/PlatformToolset_v142.png)

Below are godbolt links demonstrating this regression in `MSVC`:
1. [x64 MSVC v19.37 VS17.7](https://godbolt.org/z/x8KEvnM3b) (works)
2. [x64 MSVC v19.38 VS17.8](https://godbolt.org/z/j5hac3Mrr) (**does not** work)

Also:
- This problem reproduces in Visual Studio 2026 with the platform toolset v145.
- This problem **does not** reproduce in `C++` projects.

<h2>Steps to reproduce</h2>

1. Download the project.
2. Open the solution.
3. Ensure the platform toolset v143 is selected.
   - `Configuration Properties -> General -> Platform Toolset -> Visual Studio 2022 (v143)`.
4. Build the project.
5. Check the `Output` window or `Error List` for warnings.

<h2>Environment</h2>

Microsoft Visual Studio 2022 Version 17.14.23  
Windows 11 Version 10.0.26100 Build 26100
