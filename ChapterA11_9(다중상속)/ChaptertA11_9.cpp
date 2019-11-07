/*
	다중 상속
*/

#include <iostream>
using namespace std;

class USBDevice
{
private:
	long _id;

public:
	USBDevice(long id)
		:_id(id)
	{}

	long getID()
	{
		return _id;
	}

	void plugAndPlay()
	{}
};

class NetworkDevice
{
private:
	long _id;

public:
	NetworkDevice(long id)
		: _id(id)
	{}

	long getID()
	{
		return _id;
	}

	void networking()
	{}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id)
		: USBDevice(usb_id), NetworkDevice(net_id)
	{}
	/*
	USBNetworkDevice(long id)
		: USBDevice(id), NetworkDevice(id)
	{}
	*/
};

int main()
{
	USBNetworkDevice my_device(3.14, 6.022);

	my_device.networking();
	my_device.plugAndPlay();
	
	my_device.USBDevice::getID();
	my_device.NetworkDevice::getID();

	return 0;
}