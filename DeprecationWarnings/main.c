static __declspec(deprecated) int func()
{
    return 0;
}

int main()
{
    // 1) Deprecation warning.
    func();

    // 2) Deprecation warning.
    int a;
    a = func();

    // 3) No deprecation warning.
    int b = func();

    return 0;
}
