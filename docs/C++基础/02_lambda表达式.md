# `Lambda`表达式
## 1 什么是`Lambda`表达式?

## 2 如何使用`Lambda`表达式？
### 2.1 语法格式？
```C++
[capture_list](parameter_list)->return_type {
    /*funtion_body*/
}
```
`Lambda`表达式包含：
* `capture_list`：捕获列表，
* `parameter_list`：参数列表，
* `return_type`：返回类型，
* `function_body`：函数体。

Lambda的调用方式与普通函数的调用方式相同，都是使用调用运算符：
```C++
auto f = []{return 42;}; 
// 定义了一个可调用对象f，使用f()调用
// 可以忽略参数列表和返回类型
// 但必须永远包含捕获列表和函数体
std::cout<<f()<<std::endl; // 打印42
```
### 2.2 实质核心？
当定义一个`Lambda`时，编译器生成一个与`Lambda`对应的新的未命名的类类型。当向一个函数传递一个`Lambda`时，同时定义了一个新类型和该类型的一个对象，传递的参数就是此编译器生成的类类型的未命名对象。

### 2.3 参数列表？
与普通函数调用相似，不同的是Lambda**不能有默认参数**，故Lambda实参数目永远与形参数目相同。

```C++
[](const string &a, const string &b)
{ return a.size() < b.size();}
// 空列表表示此Lambda不使用它所在函数中的任何局部变量
stable_sort(words.begin(), words.end(),
           [] (const string &a, const string &b)
            { return a.size() < b.size();});
```

### 2.4 捕获列表？
捕获列表`[...]`的核心作用，就是让这个匿名的、局部的Lambda函数、能够访问并使用其定义时所在的作用域中的外部变量。
#### 2.4.1 值捕获

采用值捕获的前提是对象可以被拷贝，与参数不同被捕获的变量的值是在Lambda创建时拷贝，而不是调用时拷贝：

* Lambda内部操作的时这个副本，不会影响外部的原始变量。
* 默认情况下，这个副本在Lambda内部时const的，你不能修改它。如果想要修改，必须加上`mutable`关键字`[x] mutable {return x++; }`

```C++
void fcn1()
{
	size_t v1 = 42;
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();
}
```

#### 2.4.2 引用捕获

采用`&`，表明使用引用的方式捕获外部变量。注意，必须确保被引用的对象在Lambda执行的时候是存在的。

* 存在生命周期风险
* Lambda内部对引用捕获变量的任何改变，都会直接影响该外部变量。
* 引用捕获能否改变捕获的变量，取决于这个外部变量是`const`还是非`const`

```C++
void fcn2()
{
    size_t v1 = 42;
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2();
}
```

```C++
void biggies(vector<string> &words, vector<string>::size_type sz, 
            ostream &os = cout, char c = ' ')
{
	for_each(words.begin(), words.end(), 
            [&os, c](const string &s) {os << s << c;})
}
```

#### 2.4.3 隐式捕获

我们可以让编译器根据Lambda体中的代码来推断我们要使用哪些变量，为此应当在捕获列表中写一个`&`或`=`。

* `[&]`告诉编译器采用捕获引用方式
* `[=]`告诉编译器采用值捕获方式
* `[&, x]`默认引用捕获，但`x`单独指定为值捕获
* `[=, &x]`默认值捕获，但`x`单独指定为引用捕获
* `[]`禁止任何隐式捕获

```C++
int x=1, y=2;
auto f = [=, &y]() mutable {/*function body*/}
// x采用隐式捕获，y采用引用捕获
```
### 2.5 `Lambda`的返回值
默认情况下，如果一个`Lambda`体包含`return`之外的任何语句，则编译器假定此`Lambda`返回`void`，被推断为`void`的`lambda`不能返回值。

```c++
transform(vi.begin(), vi.end(). vi.begin(),
[](int i) {if (i < 0) return -i; else return i;});
// 编译去推断这个Lambda返回类型为void，但其返回了一个int值
```

当需要为一个lambda定义返回类型时，必须使用尾置返回类型。

```C++
transform(vi.begin(), vi.end(). vi.begin(),
[](int i)->int 
          { if (i < 0) return -i; else return i; });
// 正确！
```

## 3 为什么要引入`Lambda`表达式？
在C++11之前，如果我们需要给算法传递一个自定义的比较或判断逻辑，为算法函数提供一个可调用的对象。对于一个对象或一个表达式，如果可以对其使用调用运算符，就称其为可调用对象。`e(args)`中，`e`为一个可调用对象：
* 函数和函数指针
* 一个函数对象（一个重载了`operator()`的`struct`或`class`）

使用Lambda可以使得我们在需要的地方**就地**定义一个**匿名的、小巧的、一次性**的函数，让代码**更紧凑、可读性**也更强。