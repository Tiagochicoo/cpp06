#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

class Serializer
{
	private:

	public:

		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
		

};

std::ostream &			operator<<( std::ostream & o, Serializer const & i );

#endif /* ****************************************************** SERIALIZER_H */