#define CATCH_CONFIG_RUNNER

#include <QApplication>

#include "catch.hpp"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	int result = Catch::Session().run(argc, argv);

	return result < 0xff ? result : 0xff;
}
