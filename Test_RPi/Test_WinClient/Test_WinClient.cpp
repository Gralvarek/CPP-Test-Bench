// Test_WinClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <ctime>

#ifdef _WIN32
#define _WIN32_WINNT 0x0601
#endif 
#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/internet.hpp>
#include <asio/ts/buffer.hpp>
std::vector<char> buffer(1024);


void GrabSomeData(asio::ip::tcp::socket& socket)
{
	socket.async_read_some(asio::buffer(buffer.data(), buffer.size()),
		[&](std::error_code ec, std::size_t length)
		{
			if (!ec)
			{
				std::cout << "\n\nRead " << length << " bytes\n\n";

				for (uint32_t i = 0; i < length; i++)
					std::cout << buffer[i];

				GrabSomeData(socket);
			}
		}
	);
}


int main()
{

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(2000ms);
	

	asio::error_code ec;

	asio::io_context context;

	asio::io_context::work idle_work(context);

	std::thread thread_context = std::thread([&]() {context.run(); });

	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("192.168.0.248", ec), 3333);

	asio::ip::tcp::socket socket(context);
	socket.connect(endpoint, ec);

	if (!ec)
	{
		std::cout << "Connected!" << std::endl;
	}
	else
	{
		std::cout << "Failed to connect to address:\n" << ec.message() << std::endl;
	}

	if (socket.is_open())
	{
		GrabSomeData(socket);




		using namespace std::chrono_literals;
		std::this_thread::sleep_for(20000ms);

		context.stop();
		if (thread_context.joinable()) thread_context.join();

	}

	system("pause");
	return 0;
}
