#include "FsitemManager.h"

FsitemManager::FsitemManager()
{

}
FsitemManager::~FsitemManager()
{
	if (!items.empty())
		items.clear();
}

void FsitemManager::print()
{
	cout << "output tree" << endl;
	const char* resultFilePath = "output.txt";
	ofstream fl(resultFilePath);
	if (!fl)
	{
		cout << "error opening" << resultFilePath << "file" << endl;
		return;
	}
	if (items.size())
	{
		fl << items[0] << endl;
		cout << items[0] << endl;
	}
	fl.close();

}
void FsitemManager::setRoot()//������ � ����������� ���������
{
	Fsitem* item = new Fsitem();
	item->setName("");
	item->setPath("/");
	item->setType(FS_DIR);
	item->setDepth(0);
	item->setSize(0);
	items.push_back(item);
}

Fsitem* FsitemManager::getRoot()
{
	if (items.size() > 0)
	{
		return items[0];
	}
	return 0;
}

bool FsitemManager::addPath(const string path)
{
	for (int i = 0; i < paths.size(); i++)
	{
		if (path == paths[i]) return false;
		
	}
	paths.push_back(path);
	return true;
}

void FsitemManager::addFsitem(Fsitem* item)
{
	items.push_back(item);
}

void FsitemManager::addFsitem(Fsitem* item, const string prePath)
{
    for (Fsitem* candidate : items)
    {
        if (prePath == candidate->getPath())
        {
            item->setParent(candidate);
            candidate->addChild(item);
            items.push_back(item);
            break;
        }
    }
}
