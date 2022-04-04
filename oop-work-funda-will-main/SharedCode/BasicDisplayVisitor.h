#pragma once
// declaration of BasicDisplayVisitor here
// concrete visitor class
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"


class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_TextFile(TextFile* txtFile);
	void visit_ImageFile(ImageFile* imgFile);

};