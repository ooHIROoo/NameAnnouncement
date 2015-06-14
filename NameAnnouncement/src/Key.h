#pragma once
#include "boost\noncopyable.hpp"
#include "cinder\app\KeyEvent.h"
#include <set>

class NameAnnouncementApp;

namespace input{

	//�@�L�[����
class Key : private boost::noncopyable
{
	friend class NameAnnouncementApp;
	std::set<int>key_press;
	std::set<int>key_pull;
	std::set<int>key_push;
	Key() = default;
public:
	static Key& getInstance()
	{
		static Key key;
		return key;
	}

	//�@set�ɃX�^�b�N����Ă���L�[�𗬂�(�폜)
	void flush();
	void clear();

	//�@����
	//�@FixMe�F�������Ŕ���
	bool isPress(const int key_code)const{ return key_press.find(key_code) != key_press.cend(); }
	bool isPush(const int key_code)const{ return key_push.find(key_code) != key_push.cend(); }
	bool isPull(const int key_code)const{ return key_pull.find(key_code) != key_pull.cend(); }

	bool isPress(const unsigned char key_char)const{ return isPress(static_cast<int>(key_char)); }
	bool isPush(const unsigned char key_char)const{ return isPush(static_cast<int>(key_char)); }
	bool isPull(const unsigned char key_char)const{ return isPull(static_cast<int>(key_char)); }

private:
	//�@�X�^�b�N
	void setKeyDown(const int key_code);
	void setKeyUp(const int key_code);
};
}