// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h" 

void MetadataDisplayVisitor::visit_TextFile(TextFile* txtFile) {
	if (txtFile) {
		std::cout << txtFile->getName() << " " << "text " << txtFile->getSize() << std::endl;
	}
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imgFile) {
	if (imgFile) {
		std::cout << imgFile->getName() << " " << "image  " << imgFile->getSize() << std::endl;
	}
}
