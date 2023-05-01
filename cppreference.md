**Notes**
- Functions prefixed with [f] can be prefixed with `f` to force to `float`
- Functions postfixed [fl] can be postfixed `f` or `l` to force to `float` or `long double`
- Functions prefixed [ll] can be prefixed `l` or `ll` to use `long` or `long long`

## Containers
Defined in `<array>`
```cpp
std::array<type, count> myArr{  };
myArr.fill(value)
myArr.at(index)
myArr.front()
myArr.back()
```
Defined in `<vector>`
```cpp
std::vector<type> myVec{ };
myVec.pop_back();
myVec.insert(iterator, value[s]);
```


## Defined in `<string>`
```cpp
std::to_string
std::stod
std::stoi
std::stof
```

Input handling
```cpp
// Clear the input until the next newline
std::cin.ignore(100, '\n');
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Clear failed input
if (!std::cin) {        // Check for failure
    std::cin.clear();   // Clear the failure
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any extra input
}

// Read a whole line
std::string input{ };
std::getline(std::cin, input);
```

## Defined in `<cmath>`
(all are postfixed `[fl]`)
```cpp
std::round
std::ceil
std::floor
std::pow
std::[f]abs
std::fmod
std::fmax
std::fmin
std::exp            // E raised to a power
std::exp2           // 2 raised to a power
std::log            // log base e
std::log10          // log base 10
std::log2           // log base 2

std::pow            // x raised to the y
std::sqrt
std::sin            // Also cos, tan, asin, ...
```


## Defined in `<cstdlib>`
```cpp
std::[ll]abs
std::[ll]div        // Finds quotient and remainder - returns std::div_t
struct std::div_t { int quot; int rem; };
```

## defined in `<random>`
Generating random numbers
```cpp
// Create a mersenne twister random number generator
// Seed with random_device for different results
// Don't use random_device other places b/c it's implementation defined
std::mt19937 mt{ std::mt19937 mt{ std::random_device{}() }; };
// Uniform_int_distribution splits the random numbers evenly
// So this should be a fair die
std::uniform_int_distribution<> die6{ 1, 6 };
// Roll a die
std::cout << die6(mt) << '\t';
```