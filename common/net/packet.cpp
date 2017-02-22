#include "packet.h"
#include "endian.h"
#include <fmt/format.h>
#include <cctype>

void EQ::Net::Packet::PutInt8(uint64_t offset, int8_t value)
{
	if (Length() < offset + 1) {
		if (!Resize(offset + 1)) {
			throw std::out_of_range("Packet::PutInt8(), could not resize packet and would of written past the end.");
		}
	}

	*(int8_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutInt16(uint64_t offset, int16_t value)
{
	if (Length() < offset + 2) {
		if (!Resize(offset + 2)) {
			throw std::out_of_range("Packet::PutInt16(), could not resize packet and would of written past the end.");
		}
	}

	*(int16_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutInt32(uint64_t offset, int32_t value)
{
	if (Length() < offset + 4) {
		if (!Resize(offset + 4)) {
			throw std::out_of_range("Packet::PutInt32(), could not resize packet and would of written past the end.");
		}
	}

	*(int32_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutInt64(uint64_t offset, int64_t value)
{
	if (Length() < offset + 8) {
		if (!Resize(offset + 8)) {
			throw std::out_of_range("Packet::PutInt64(), could not resize packet and would of written past the end.");
		}
	}

	*(int64_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutUInt8(uint64_t offset, uint8_t value)
{
	if (Length() < offset + 1) {
		if (!Resize(offset + 1)) {
			throw std::out_of_range("Packet::PutUInt8(), could not resize packet and would of written past the end.");
		}
	}

	*(uint8_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutUInt16(uint64_t offset, uint16_t value)
{
	if (Length() < offset + 2) {
		if (!Resize(offset + 2)) {
			throw std::out_of_range("Packet::PutUInt16(), could not resize packet and would of written past the end.");
		}
	}

	*(uint16_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutUInt32(uint64_t offset, uint32_t value)
{
	if (Length() < offset + 4) {
		if (!Resize(offset + 4)) {
			throw std::out_of_range("Packet::PutUInt32(), could not resize packet and would of written past the end.");
		}
	}

	*(uint32_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutUInt64(uint64_t offset, uint64_t value)
{
	if (Length() < offset + 8) {
		if (!Resize(offset + 8)) {
			throw std::out_of_range("Packet::PutUInt64(), could not resize packet and would of written past the end.");
		}
	}

	*(uint64_t*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutFloat(uint64_t offset, float value)
{
	if (Length() < offset + 4) {
		if (!Resize(offset + 4)) {
			throw std::out_of_range("Packet::PutFloat(), could not resize packet and would of written past the end.");
		}
	}

	*(float*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutDouble(uint64_t offset, double value)
{
	if (Length() < offset + 8) {
		if (!Resize(offset + 8)) {
			throw std::out_of_range("Packet::PutDouble(), could not resize packet and would of written past the end.");
		}
	}

	*(double*)((char*)Data() + offset) = value;
}

void EQ::Net::Packet::PutString(uint64_t offset, const std::string &str)
{
	if (Length() < offset + str.length()) {
		if (!Resize(offset + str.length())) {
			throw std::out_of_range("Packet::PutString(), could not resize packet and would of written past the end.");
		}
	}

	memcpy(((char*)Data() + offset), str.c_str(), str.length());
}

void EQ::Net::Packet::PutCString(uint64_t offset, const char *str)
{
	uint64_t sz = strlen(str);
	if (Length() < offset + sz + 1) {
		if (!Resize(offset + sz + 1)) {
			throw std::out_of_range("Packet::PutCString(), could not resize packet and would of written past the end.");
		}
	}

	memcpy(((char*)Data() + offset), str, (size_t)sz);
	*((char*)Data() + offset + sz) = 0;
}

void EQ::Net::Packet::PutPacket(uint64_t offset, const Packet &p)
{
	if (Length() < offset + p.Length()) {
		if (!Resize(offset + p.Length())) {
			throw std::out_of_range("Packet::PutPacket(), could not resize packet and would of written past the end.");
		}
	}

	memcpy(((char*)Data() + offset), p.Data(), (size_t)p.Length());
}

void EQ::Net::Packet::PutData(uint64_t offset, void *data, uint64_t length)
{
	if (Length() < offset + length) {
		if (!Resize(offset + length)) {
			throw std::out_of_range("Packet::PutData(), could not resize packet and would of written past the end.");
		}
	}

	memcpy(((char*)Data() + offset), data, (size_t)length);
}

int8_t EQ::Net::Packet::GetInt8(uint64_t offset) const
{
	if (Length() < offset + 1) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(int8_t*)((char*)Data() + offset);
}

int16_t EQ::Net::Packet::GetInt16(uint64_t offset) const
{
	if (Length() < offset + 2) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(int16_t*)((char*)Data() + offset);
}

int32_t EQ::Net::Packet::GetInt32(uint64_t offset) const
{
	if (Length() < offset + 4) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(int32_t*)((char*)Data() + offset);
}

int64_t EQ::Net::Packet::GetInt64(uint64_t offset) const
{
	if (Length() < offset + 8) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(int64_t*)((char*)Data() + offset);
}

uint8_t EQ::Net::Packet::GetUInt8(uint64_t offset) const
{
	if (Length() < offset + 1) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(uint8_t*)((char*)Data() + offset);
}

uint16_t EQ::Net::Packet::GetUInt16(uint64_t offset) const
{
	if (Length() < offset + 2) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(uint16_t*)((char*)Data() + offset);
}

uint32_t EQ::Net::Packet::GetUInt32(uint64_t offset) const
{
	if (Length() < offset + 4) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(uint32_t*)((char*)Data() + offset);
}

uint64_t EQ::Net::Packet::GetUInt64(uint64_t offset) const
{
	if (Length() < offset + 8) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(uint64_t*)((char*)Data() + offset);
}

float EQ::Net::Packet::GetFloat(uint64_t offset) const
{
	if (Length() < offset + 4) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(float*)((char*)Data() + offset);
}

double EQ::Net::Packet::GetDouble(uint64_t offset) const
{
	if (Length() < offset + 8) {
		throw std::out_of_range("Packet read out of range.");
	}

	return *(double*)((char*)Data() + offset);
}

std::string EQ::Net::Packet::GetString(uint64_t offset, uint64_t length) const
{
	if (Length() < offset + length) {
		throw std::out_of_range("Packet read out of range.");
	}

	return std::string((char*)Data() + offset, (char*)Data() + offset + length);
}

std::string EQ::Net::Packet::GetCString(uint64_t offset) const
{
	if (Length() < offset + 1) {
		throw std::out_of_range("Packet read out of range.");
	}

	char *str = ((char*)Data() + offset);
	return std::string(str);
}

char ToSafePrint(unsigned char in) {
	if (std::isprint(in)) {
		return in;
	}

	return '.';
}

std::string EQ::Net::Packet::ToString() const
{
	return ToString(16);
}

std::string EQ::Net::Packet::ToString(uint64_t line_length) const
{
	if (Length() == 0) {
		return fmt::format("{:0>5x} |", 0);
	}

	std::string ret;
	uint64_t lines = Length() / line_length;
	uint64_t i;

	char *data = (char*)Data();

	for (i = 0; i < lines; ++i) {
		ret += fmt::format("{:0>5x} |", i * line_length);
		std::string hex;
		std::string ascii;
		for (uint64_t j = 0; j < line_length; ++j) {
			hex += fmt::format(" {:0>2x}", (uint8_t)data[(i * line_length) + j]);
			ascii += fmt::format("{}", ToSafePrint(data[(i * line_length) + j]));
		}

		ret += hex;
		ret += " | ";
		ret += ascii;
		ret += "\n";
	}

	if (Length() % line_length > 0) {
		ret += fmt::format("{:0>5x} |", i * line_length);

		uint64_t non_blank_count = Length() % line_length;
		uint64_t blank_count = line_length - non_blank_count;
		std::string hex;
		std::string ascii;

		for (uint64_t j = 0; j < non_blank_count; ++j) {
			hex += fmt::format(" {:0>2x}", (uint8_t)data[(i * line_length) + j]);
			ascii += fmt::format("{}", ToSafePrint(data[(i * line_length) + j]));
		}

		for (uint64_t j = 0; j < blank_count; ++j) {
			hex += "   ";
			ascii += " ";
		}

		ret += hex;
		ret += " | ";
		ret += ascii;
		ret += "\n";
	}

	return ret;
}

bool EQ::Net::StaticPacket::Resize(uint64_t new_size)
{
	if (new_size > m_max_data_length) {
		return false;
	}

	m_data_length = new_size;
	return true;
}