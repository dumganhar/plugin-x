package org.cocos2dx.plugin;

import java.util.Hashtable;

public class InterfaceIAP {
	public static final int PAYRESULT_SUCCESS = 0;
	public static final int PAYRESULT_FAIL    = 1;
	public static final int PAYRESULT_CANCEL  = 3;
	public static final int PAYRESULT_TIMEOUT = 4;

	public interface IAPAdapter {
		public void initDeveloperInfo(Hashtable<String, String> cpInfo);
		public void payForProduct(Hashtable<String, String> cpInfo);
		public void setDebugMode(boolean debug);
		public String getSDKVersion();
	}

	public static native void nativePayResult(int ret, String msg);
}
