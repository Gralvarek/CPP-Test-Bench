#include <iostream>
#include <chrono>
#include <ctime>

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>

int main()
{

	asio::error_code ec;

	asio::io_context context;
	asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 3333);

	asio::ip::tcp::acceptor acceptor(context, endpoint);

	asio::ip::tcp::socket socket(context);
	try
	{
		acceptor.accept(socket);
		std::cout << "Connection Accepted\n";
		std::string message = "Hello, World";
		socket.write_some(asio::buffer(message, message.size()), ec);
		std::cout << "Data Sent\n";
		context.stop();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exeception: " << e.what() << "\n";
		return -1;
	}


    return 0;
}