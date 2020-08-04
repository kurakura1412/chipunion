/*
chipunion PS(R) ps2 to ps3 
vid 2563 pid 0575
the device name PS2TO4IN1 
released in 2017
mass produced in china before corona pandemic

original Report Descriptor Size: 137
old Report Descriptor Data:
	05 01 09 05 a1 01 15 00 25 01 35 00 45 01 75 01 95 0d 05 09 19 01 29 0d 
	81 02 95 03 81 01 05 01 25 07 46 3b 01 75 04 95 01 65 14 09 39 81 
	42 75 04 95 01 81 01 26 ff 00 46 ff 00 09 30 09 31 09 32 09 35 75 08 
	95 04 81 02 06 00 ff 09 20 09 21 09 22 09 23 09 24 09 25 09 26 09 27 
	09 28 09 29 09 2a 09 2b 95 0c 81 02 0a 21 26 95 08 b1 02 0a 21 26 91 
	02 26 ff 03 46 ff 03 09 2c 09 2d 09 2e 09 2f 75 10 95 04 81 02 c0 
old Report Descriptor:
 05 01     	Usage Page (Generic Desktop)
 09 05     	Usage (Game Pad)
 a1 01     	Collection (Application)
 15 00     		Logical Minimum (0)
 25 01     		Logical Maximum (1)
 35 00     		Physical Minimum (0)
 45 01     		Physical Maximum (1)
 75 01     		Report Size (1)
 95 0d     		Report Count (13)
 05 09     		Usage Page (Button)
 19 01     		Usage Minimum (1)
 29 0d     		Usage Maximum (13)
 81 02     		Input (Variable) //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
 95 03     		Report Count (3)
 81 01     		Input (Constant)//   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
 05 01     		Usage Page (Generic Desktop)
 25 07     		Logical Maximum (7)
 46 3b 01		Physical Maximum (-32508)
 75 04     		Report Size (4)
 95 01     		Report Count (1)
 65 14     		Unit (Degrees)
 09 39     		Usage (Hat Switch)
 81 42     		Input (Variable, Null state)//   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
 75 04     		Report Size (4)
 95 01     		Report Count (1)
 81 01     		Input (Constant)//   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
 26 ff 00  		Logical Maximum (-20216)
 46 ff 00  		Physical Maximum (657)
 09 30     		Usage (X axis)
 09 31     		Usage (Y axis)
 09 32     		Usage (Z axis)
 09 35     		Usage (Rz axis)
 75 08     		Report Size (8)
 95 04     		Report Count (4)
 81 02     		Input (Variable)//   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
 06 00 ff  		Usage Page (Undefined)
 09 20     		Usage (0x0020)
 09 21     		Usage (0x0021)
 09 22     		Usage (0x0022)
 09 23     		Usage (0x0023)
 09 24     		Usage (0x0024)
 09 25     		Usage (0x0025)
 09 26     		Usage (0x0026)
 09 27     		Usage (0x0027)
 09 28     		Usage (0x0028)
 09 29     		Usage (0x0029)
 09 2a     		Usage (0x002a)
 09 2b     		Usage (0x002b)
 95 0c     		Report Count (12)
 81 02     		Input (Variable)//   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
 0a 21 26		Usage (0x0000)
 95 08     		Report Count (8)
 b1 02     		Feature (2)//   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
 0a 21 26		Usage (0x0000)
 91 02     		Output (Variable)/   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
 26 ff 03  		Logical Maximum (0)
 46 ff 03  		Physical Maximum (0)
 09 2c     		Usage (0x002c)
 09 2d     		Usage (0x002d)
 09 2e     		Usage (0x002e)
 09 2f      		Usage (0x002f)
 75 10     		Report Size (16)
 95 04     		Report Count (4)
 81 02     		Input (Variable) //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
 c0          		End Collection (0)
*/

//#define DEBUG
#define debug(format, arg...) pr_debug("hid-plff: " format "\n" , ## arg)
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/hid.h>
#include <linux/delay.h>
#include "hid-ids.h"

#define PID0575_RDESC_ORIG_SIZE 137
#define NUM_LEDS 1


static __u8 *chip_report_fixup(struct hid_device *hdev, __u8 *rdesc,
				unsigned int *rsize)
{
	//hid_info(hdev, "on_report_fixup\n");
//*
	if (*rsize == PID0575_RDESC_ORIG_SIZE) {
		//rdesc = pid0575_rdesc_fixed;
		//*rsize = sizeof(pid0575_rdesc_fixed);
		//rdesc[3] = 0x04; // joystick
	} else
		hid_warn(hdev, "unexpected rdesc, please submit for review\n");
//*/
	return rdesc;
}
//static int chip_input_configured(struct hid_device *hdev,	struct hid_input *hidinput)
static void chip_input_configured(struct hid_device *hdev,	struct hid_input *hidinput)
{
	//hid_info(hdev, "on_input_configured\n");
	//hdev->quirks |= HID_QUIRK_NO_OUTPUT_REPORTS_ON_INTR_EP;
	//hdev->quirks |= HID_QUIRK_SKIP_OUTPUT_REPORT_ID;
	//hdev->quirks |= HID_QUIRK_BADPAD;
	//return 0;
}
static inline int plff_init(struct hid_device *hdev)
{
	//hid_info(hdev, "on_forcefeedback<!>\n");
	return 0;
}

static int chip_probe(struct hid_device *hdev, const struct hid_device_id *id)
{
	int ret,error;
	unsigned int myquirk =0;
	unsigned int connect_mask = 0;
	//hid_info(hdev, "on_probe\n");
	
	if (id->driver_data)
		hdev->quirks |= HID_QUIRK_MULTI_INPUT;
	
	// need this quirk.
	// itherwise, device send -EPIPE on GET_REPORT 
	// because linux sent URBCOTROL on INTERUPT CHANNEL!!
	myquirk = (HID_QUIRK_NOGET); 
	hdev->quirks |= myquirk;
	
	ret = hid_parse(hdev);
	//hid_info(hdev, "on_probe parse done\n");
	if (ret) {
		hid_err(hdev, "parse failed\n");
		goto err;
	}
	//hid_info(hdev, "on_sleep<!>\n");
	//ssleep(1);
	
	// ~HID_CONNECT_FF just there for future update:
	connect_mask = (HID_CONNECT_DEFAULT) ;
	connect_mask &= ~HID_CONNECT_FF;

	//* lets we start it
	ret = hid_hw_start(hdev, connect_mask);
	
	if (ret) {
		hid_err(hdev, "hw start failed\n");
		goto err;
	}
	//*/
	//ssleep(1);
	//if (!(hdev->claimed & HID_CLAIMED_INPUT)) {
	//	hid_err(hdev, "failed to claim input\n");
	//	return -ENODEV;
	//}
	//ssleep(1);
	plff_init(hdev);

	// We need to start polling device right away, otherwise
	// it will go into a coma. 
	// we need this or the device will restarting over and over.
	// hid_info(hdev, "on hid_hw_open<!>\n");
	error = hid_hw_open(hdev);
	if (error) {
		dev_err(&hdev->dev, "hw open failed\n");
		hid_hw_stop(hdev);
		return error;
	}
	
	
	return 0;
err:
	return ret;
}
static int chip_raw_event(struct hid_device *hdev, struct hid_report *report,
		u8 *rd, int size)
{
	//hid_info(hdev, "on_raw<!>s:%d\n", size);
	//hid_info(hdev, "raw <!>\n");
	return 0;
}
static void chip_remove(struct hid_device *hdev)
{
	hid_warn(hdev, "chipmunk USB device removed\n");
	hid_hw_close(hdev);
	hid_hw_stop(hdev);
}
#ifdef CONFIG_PM
static int chip_suspend(struct hid_device *hdev, pm_message_t message)
{
	hid_warn(hdev, "chipmunk USB device SUSPEND\n");
	return 0;
}

#endif
static const struct hid_device_id chip_devices[] = {
	{ HID_USB_DEVICE( 0x2563 , 0x0575) , },
	{ }
};



static struct hid_driver chipunion_driver = {
	.name             = "ChipUnion",
	.id_table         = chip_devices,
	
//	.input_mapping    = chipunion_mapping,
	
	.input_configured = chip_input_configured,
	
	.probe            = chip_probe,
	.remove           = chip_remove,
	.report_fixup     = chip_report_fixup,
	.raw_event        = chip_raw_event,
//	.disconnect = chip_disconnect,

#ifdef CONFIG_PM
	.suspend          = chip_suspend,
	//.resume	          = chipunion_resume,
	//.reset_resume     = chipunion_resume,
#endif
	//*/
};
//*
static int __init chipunion_init(void)
{
	dbg_hid("linux-chipunion loading module:%s\n", __func__);

	return hid_register_driver(&chipunion_driver);
}

static void __exit chipunion_exit(void)
{
	dbg_hid("linux-chipunion unload:%s\n", __func__);

	hid_unregister_driver(&chipunion_driver);
//	ida_destroy(&chipunion_device_id_allocator);
}
module_init(chipunion_init);
module_exit(chipunion_exit);
//*/
//module_hid_driver(chipunion_driver);
MODULE_DESCRIPTION("ChipUnion PS2TO4IN1 vid 2563 pid 0575");
MODULE_LICENSE("GPL");
