// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>  

void BasicDisplayVisitor::visit_TextFile(TextFile* txtFile) {
	if (txtFile) {
		for (auto& e : txtFile->read()) {
			std::cout << e;
		}
		std::cout << std::endl;
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imgFile) {
	if (imgFile) {
		std::vector<char> content = imgFile->read();
		std::stringstream image_ss;
		const unsigned int Size = static_cast<unsigned int>(std::sqrt(imgFile->getSize()));
		for (unsigned int i = Size; i > 0; --i) {
			for (unsigned int j = 1; j <= Size; ++j) {
				image_ss << content[imgFile->index(j - 1, i - 1)] ;
			}
			image_ss << "\n";
		}
		std::cout << image_ss.str();
	}
}