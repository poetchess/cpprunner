exercise 6.36:
    string (& func(void))[10];

exercise 6.37:
    typedef string T[10];
    using T = string[10];
    T& func(void);

    auto func(void) -> string (&) [10];

    string s[10] = {};
    decltype(s) &func(void);

exercise 6.38:
    int odd[] = {1, 3, 5, 7, 9};
    int even[] = {2, 4, 6, 8, 10};
    auto attrPtr(int i) -> int (&) [5]
    {
        return (i % 2) ? odd : even;
    }