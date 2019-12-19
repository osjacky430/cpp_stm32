/**
 * @Date:   2019-12-19T02:54:43+08:00
 * @Email:  osjacky430@gmail.com
 * @Filename: utility.hxx
 */

#define SETUP_REGISTER_INFO(Name, ...)                 \
	class Name {                                         \
		template <typename BitList, std::size_t Idx>       \
		friend constexpr auto get_bit() noexcept;          \
                                                       \
	 private:                                            \
		static constexpr std::tuple BIT_LIST{__VA_ARGS__}; \
	};
