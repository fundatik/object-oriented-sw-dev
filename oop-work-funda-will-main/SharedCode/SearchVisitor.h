#pragma once
#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"


class SearchVisitor : public AbstractFileVisitor {
public:
	//constructors
	SearchVisitor();
	SearchVisitor(std::string);

	void visit_TextFile(TextFile*) override;
	void visit_ImageFile(ImageFile*) override;

private:
	std::string keyword_;
	// passed in via the constructor, used to compared with the file content
};