#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

// T& means th callback may modify the element
template <typename T, typename Func> 
void iter(T *arr, const int len, Func func)
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T, typename Func> 
void iter(const T *arr, const int len, Func func)
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template <typename T> 
void print(const T& value)
{
	std::cout << value << " ";
}

template <typename T>
void increment(T& value)
{
	value++;
	std::cout << value << " ";
}

template<typename T>
void decrement(T& value)
{
	value--;
	std::cout << value << " ";
}

#endif