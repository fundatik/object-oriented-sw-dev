#pragma once
// declaration of MetadataDisplayVisitor here

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"


class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_TextFile(TextFile* txtFile);
	void visit_ImageFile(ImageFile* imgFile);

};