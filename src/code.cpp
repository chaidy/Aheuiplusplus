#include <Aheuiplusplus/code.hpp>

#include <stdexcept>

namespace app
{
	bool is_complete_hangul(char32_t character) noexcept
	{
		return character >= 0xAC00 && character <= 0xD7A3;
	}
	char32_t get_chosung(char32_t hangul)
	{
		if (!is_complete_hangul(hangul))
			throw std::invalid_argument("�μ� hangul�� �ϼ��� ���� �ѱ��̿��� �մϴ�.");

		static constexpr char32_t chosungs[] = {
			U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��',
			U'��', U'��', U'��', U'��', U'��', U'��'
		};

		return chosungs[((((hangul - 0xAC00) - ((hangul - 0xAC00) % 28)) / 28) - ((((hangul - 0xAC00) - ((hangul - 0xAC00) % 28)) / 28) % 21)) / 21];
	}
	char32_t get_jungsung(char32_t hangul)
	{
		if (!is_complete_hangul(hangul))
			throw std::invalid_argument("�μ� hangul�� �ϼ��� ���� �ѱ��̿��� �մϴ�.");

		static constexpr char32_t jungsungs[] = {
			U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��',
			U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��'
		};

		return jungsungs[(((hangul - 0xAC00) - ((hangul - 0xAC00) % 28)) / 28) % 21];
	}
	char32_t get_jongsung(char32_t hangul)
	{
		if (!is_complete_hangul(hangul))
			throw std::invalid_argument("�μ� hangul�� �ϼ��� ���� �ѱ��̿��� �մϴ�.");

		static constexpr char32_t jongsungs[] = {
			0, U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��',
			U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��', U'��'
		};

		return jongsungs[(hangul - 0xAC00) % 28];
	}
}