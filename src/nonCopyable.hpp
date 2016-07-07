#ifndef NONCOPYABLE_HPP
#define NONCOPYABLE_HPP

struct NonCopyable
{
	NonCopyable( void ) noexcept { };

	NonCopyable( const NonCopyable& that ) = delete;
	NonCopyable& operator=( const NonCopyable& that ) = delete;
};

#endif
