#ifndef NETMESSAGE_H
#define NETMESSAGE_H



namespace net 
{

	template<typename T>
	struct MessageHeader
	{
		T id;
		uint32_t size = 0;
	};

	template<typename T>
	struct Message
	{
		MessageHeader<T> header;
		std::vector<uint8_t> body;
		
		size_t size() const
		{
			return sizeof(MessageHeader<T>) + body.size();
		}

		friend std::ostream& operator << (std::ostream& os, const Message<T> msg)
		{
			os << "ID:" << int(msg.header.id) << " Size:" << msg.header.size;
			return os;
		}

		template<typename DataType>
		friend Message<T>& operator << (Message<T>& msg, const DataType& data)
		{
			static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to be pushed into vector.");

			size_t i = msg.body.size();

			msg.body.resize(msg.body.size() + sizeof(DataType));

			std::memcpy(msg.body.data() + i, &data, sizeof(DataType));

			msg.header.size = msg.size();

			return msg;

		}

		template<typename DataType>
		friend Message<T>& operator >> (Message<T>& msg, DataType& data)
		{
			static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to be pushed into vector.");

			size_t i = msg.body.size() - sizeof(DataType);

			std::memcpy(&data, msg.body.data() + i, sizeof(DataType));

			msg.body.resize(i);

			msg.header.size = msg.size();

			return msg;

		}

	};

}








#endif