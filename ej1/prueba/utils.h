//utils.h
#ifndef UTILS_H_
#define UTILS_H_

#include <stack>
#include <queue>
// FUNCIONES UTILITARIAS

// Imprimir lista
template <typename T>
void printl(const list<T>& pepina)
{
	for (auto c: pepina)
	{
		for (auto d: c)
			cout << " " << d;
		cout << endl;
	}	
}
// FIN Imprimir lista


// Imprimir vector
template <typename T>
void printv(const std::vector<T>& v)
{
	for (auto i: v)
		cout << i << " / " ;
	cout << endl;
}
// FIN Imprimir vector


// Imprimir stack

template <class Container, class Stream>
Stream& printOneValueContainer
    (Stream& outputstream, const Container& container)
{
    typename Container::const_iterator beg = container.begin();

    outputstream << "[";

    while(beg != container.end())
    {
        outputstream << " " << *beg++;
    }

    outputstream << " ]";

    return outputstream;
}

template < class Type, class Container >
const Container& container
    (const std::stack<Type, Container>& stack)
{
    struct HackedStack : private std::stack<Type, Container>
    {
        static const Container& container
            (const std::stack<Type, Container>& stack)
        {
            return stack.*&HackedStack::c;
        }
    };

    return HackedStack::container(stack);
}

template < class Type, class Container >
const Container& container
    (const std::queue<Type, Container>& queue)
{
    struct HackedQueue : private std::queue<Type, Container>
    {
        static const Container& container
            (const std::queue<Type, Container>& queue)
        {
            return queue.*&HackedQueue::c;
        }
    };

    return HackedQueue::container(queue);
}

template
    < class Type
    , template <class Type, class Container = std::deque<Type> > class Adapter
    , class Stream
    >
Stream& operator<<
    (Stream& outputstream, const Adapter<Type>& adapter)
{
    return printOneValueContainer(outputstream, container(adapter));
}


// FIN Imprimir stack



#endif