#include <iostream>
#include <string>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char * argv[])
{
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13)));				//port 13
		if (!stream)
		{
			std::cout << "Unable to connect : " << stream.error().message() << std::endl;
			return 1;
		}

		// send message to server
		stream << "hello from client";
		stream << std::endl;	// send new-line to end receiver'stream getline

		// receive message from server
		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}