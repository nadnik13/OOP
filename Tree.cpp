#include "Tree.h"
#include <iostream>
#include <memory>

Tree::Tree()
{
	root = nullptr;
};

Tree::Tree(std::shared_ptr<TreeItem> tr)
{
	root = tr;
}
Tree::Tree(const Tree &orig)
{
	this->root = orig.root;
};

void Tree::PushRoot(std::shared_ptr<Polygon> elem)
{
	std::shared_ptr<TreeItem> newPtrElem(new TreeItem(elem));
	root = newPtrElem;
}

void Tree::Push(std::shared_ptr<Polygon> from, std::shared_ptr<Polygon> elem)
{
	std::shared_ptr<TreeItem> fr = Search(from, root);
	if (fr != nullptr)
	{
		if (fr->GetSon())
		{
			fr = fr->GetSon();
			while (fr->GetBrother())
			{
				fr = fr->GetBrother();
			}
			std::shared_ptr<TreeItem> newPtrElem(new TreeItem(fr, elem));
			fr->SetBrother(newPtrElem);
			return;
		}
		else
		{
			std::shared_ptr<TreeItem> newPtrElem(new TreeItem(fr, elem));
			fr->SetSon(newPtrElem);
			return;
		}
	}
	else
	{
		std::cout << "Not Found" << std::endl;
		return;
	}
};

bool Tree::Empty(){
	bool check = false;
	if (root == nullptr) check=true;
	if (check) std::cout<<"Tree is empty"<<std::endl;
	return check;
}

void Tree::Print()
{

	size_t b = 0;
	Empty();
	PrintTree(root, b);
}

void Tree::PrintTree(std::shared_ptr<TreeItem> cur, size_t buf)
{
	if (cur != nullptr)
	{
		for (size_t i = 0; i < buf; i++)
		{
			std::cout << "    ";
		}
		std::cout << *cur << std::endl;
		PrintTree(cur->GetSon(), buf + 2);
		PrintTree(cur->GetBrother(), buf);
	}
}

void Tree::Delete(std::shared_ptr<Polygon> elem)
{
	std::shared_ptr<TreeItem> fr = Search(elem, root);
	if (fr->GetParent()->GetSon() == fr)
	{
		fr->GetParent()->SetSon(nullptr);
	}
	else
	{
		fr->GetParent()->SetBrother(nullptr);
	}
	fr->SetBrother(nullptr);
	fr->SetSon(nullptr);
}

std::shared_ptr<TreeItem> Tree::Search(std::shared_ptr<Polygon> poly, std::shared_ptr<TreeItem> currentElem)
{
	if (currentElem == nullptr)
	{
		return nullptr;
	}
	if (*(currentElem->figure) == *(poly))
	{
		return currentElem;
	}
	else
	{
		std::shared_ptr<TreeItem> find = nullptr;
		find = Search(poly, currentElem->GetSon());
		if (find == nullptr)
			find = Search(poly, currentElem->GetBrother());
		return find;
	}
}

void Tree::Destroy(){
	root=nullptr;
	std::cout<<"i am die 0_0"<<std::endl;
}

Tree::~Tree(){
	std::cout<<"i am die";

}
