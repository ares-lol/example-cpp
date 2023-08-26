#include <includes.hpp>

std::uint32_t main() {
	std::vector<std::uint32_t> app_encrypted = { 62415, 62414, 62409, 62410, 62361, 62407, 62409, 62366, 62418, 62409, 62413, 62408, 62411, 62418, 62411, 62365, 62406, 62410, 62418, 62365, 62362, 62413, 62364, 62418, 62408, 62361, 62415, 62408, 62413, 62413, 62408, 62414, 62366, 62363, 62414, 62361 };

	ares::session_ctx session_ctx = ares::connect(app_encrypted);

	std::string license;
	std::cin >> license;

	ares::response_e response = session_ctx.authenticate(license);

	if (response != ares::valid) {
		if (response == ares::hwid) {
			printf("HWID does not match!\n");
		}
		else if (response == ares::banned) {
			printf("Banned!\n");
		}
		else if (response == ares::expired) {
			printf("Expired!\n");
		}
		else {
			printf("Invalid!\n");
		}
		return 0;
	}

	ares::license_ctx license_ctx = session_ctx.license_ctx();

	std::printf("Valid!\nExpiry: %s\nHWID: %s\nIP: %s\nLast Login: %s\nVariable windowshopper: %s\n", license_ctx.expiry().c_str(), license_ctx.hwid().c_str(), license_ctx.ip().c_str(), license_ctx.lastLogin().c_str(), session_ctx.variable("windowshopper"));

	ares::secure_image_ctx image_ctx = session_ctx.module("a590b336-ff74-477b-9564-93ba8d30118e");
	std::printf("image streamed!\n");

	std::vector<std::uint32_t> decrypted = image_ctx.decrypt();
	std::printf("%i\n", decrypted.size());
	for (char c : decrypted) {
		std::printf("%c", c);
	}

	std::printf("natural exit\n");
}