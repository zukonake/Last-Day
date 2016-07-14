#ifndef NONCOPYABLE_HPP
#define NONCOPYABLE_HPP

class NonCopyable
{
protected:
	NonCopyable( void ) = default;
	virtual ~NonCopyable( void ) = default;

	NonCopyable( const NonCopyable& that ) = delete;
	NonCopyable& operator=( const NonCopyable& that ) = delete;
};

#endif
