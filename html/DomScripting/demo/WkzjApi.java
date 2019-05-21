package net.wkzj.api.remote;

import android.content.Context;
import android.os.Build;

import com.loopj.android.http.AsyncHttpResponseHandler;
import com.loopj.android.http.RequestParams;

import net.wkb.utils.StringUtils;
import net.wkb.utils.common.Constants;
import net.wkzj.api.ApiClientHelper;
import net.wkzj.api.ApiHttpClient;

import org.apache.http.entity.StringEntity;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.FileInputStream;

public class WkzjApi {

    /**
     * 登陆 +++
     *
     * @param usertitle
     * @param password
     * @param handler
     */
    public static void login(String usertitle, String password, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("usertitle", usertitle);
        params.put("password", password);
        params.put("from", Constants.PTYPE);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login", params, handler);
    }

    /**
     * 获取用户信息
     */
    public static void userInfo(String token, String clientId, String deviceName, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.setAPIVersion("1");
            RequestParams params = new RequestParams();
            params.put("clientid", clientId);
            params.put("devicename", deviceName);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.setAPIVersion("1");
            ApiHttpClient.post("service/login/extrainfo", params, handler);
        }
    }

    /**
     * 登出 +++
     *
     * @param handler
     */
    public static void logout(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/login/logout", handler);
        }
    }

    /**
     * 获取参数
     *
     * @param handler
     */
    public static void redirectParam(String token, AsyncHttpResponseHandler handler, String type) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            RequestParams params = new RequestParams();
            params.put("type", type);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/wkb/redirectparam", params, handler);
        }
    }

    /**
     * 获取pdf信息 +++
     *
     * @param pageNum
     * @param pageSize
     * @param handler
     */
    public static void getPdfList(String token, int pageNum, int pageSize, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("currentPage", pageNum);
            params.put("pageSize", pageSize);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/wkbresources", params, handler);
        }
    }

    /**
     * 获取audio信息 +++
     *
     * @param start
     * @param handler
     */
    public static void getAudioList(String token, int start, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("start", start);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/audiolist", params, handler);
        }
    }

    /**
     * 获取直播信息 +++
     *
     * @param start
     * @param handler
     */
    public static void getLiveList(String token, int start, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("start", start);
        params.setUseJsonStreamer(true);
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/live/wkblist", params, handler);
    }

    public static void startLive(String token, int id, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("lcid", id);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/live/startlive", params, handler);
        }
    }

    public static void endLive(String token, int id, AsyncHttpResponseHandler handler) {
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("lcid", id);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/live/endlive", params, handler);
        }
    }

    public static void startwarmup(String token, int id, AsyncHttpResponseHandler handler) {
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("lcid", id);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/live/startwarmup", params, handler);
        }
    }

    /**
     * 查询我的班级列表 +++
     *
     * @param handler
     */
    public static void getMyClassList(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/profile/getmyclass", handler);
        }
    }

    /**
     * 查询我的班级列表 +++
     *
     * @param handler
     */
    public static void getMyClassList2(String token, AsyncHttpResponseHandler handler) {
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/classes/mylist", handler);
        }
    }

    /**
     * 获取PPT信息
     *
     * @param url
     * @param handler
     */
    public static void getPPTInfo(String url, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.get2(url, handler);
    }


    /******************
     *   新版资源列表  *
     ******************/

    /**
     * 教研组列表
     *
     * @param handler
     */
    public static void groupList(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/grouplist", handler);
        }
    }

    /**
     * 教研组资源
     *
     * @param params
     * @param handler
     */
    public static void groupResource(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/groupresource", params, handler);
        }
    }

    /**
     * 班级列表
     *
     * @param handler
     */
    public static void classList2(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/classlist", handler);
        }
    }

    /**
     * @param params
     * @param handler
     */
    public static void classResource(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/classresource", params, handler);
        }
    }

    /**
     * 我的收藏
     *
     * @param params
     * @param handler
     */
    public static void favouriteResource(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/favouriteresource", params, handler);
        }
    }

    /**
     * 我的资源
     *
     * @param params
     * @param handler
     */
    public static void myResource(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.setAPIVersion("2");
            ApiHttpClient.post("service/wkb/myresource", params, handler);
        }
    }


    /**
     * access log ++
     */
    public static void accesslog(String appId, String mac, String version, String screen, String screenSize, int userId, String userTitle, String userName, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("SN", appId + "#" + mac);
        params.put("PTYPE", Constants.PTYPE);
        params.put("PNO", version);
        params.put("SCREEN", screen);
        params.put("OS", Constants.OSTYPE);
        params.put("OSVERSION", android.os.Build.VERSION.RELEASE);
        params.put("TERMINAL", android.os.Build.MANUFACTURER + " " + android.os.Build.MODEL);
        params.put("OPTYPE", "10");
        params.put("SCREENSIZE", screenSize);
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(userTitle)) {
            params.put("USERID", userId);
            params.put("USERTITLE", userTitle);
            params.put("USERNAME", userName);
        }
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/product/accesslog", params, handler);
    }

    /**
     * record log ++
     */
    public static void recordlog(String appId, String mac, String version, String screen, int userId, String userTitle, String userName, AsyncHttpResponseHandler handler, String memo) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        //params.put("SN", AppContext.getInstance().getAppId() + "#" +  AppContext.getInstance().getMacAddress());
        params.put("SN", appId + "#" + mac);
        params.put("PTYPE", Constants.PTYPE);
        //params.put("PNO", AppContext.getInstance().getVersion(true));
        params.put("PNO", version);
        //params.put("SCREEN", Wkb.getScreenWidth() + "x" + Wkb.getScreenHeight());
        params.put("SCREEN", screen);
        params.put("OS", Constants.OSTYPE);
        params.put("OSVERSION", android.os.Build.VERSION.RELEASE);
        params.put("TERMINAL", android.os.Build.MANUFACTURER + " " + android.os.Build.MODEL);
        params.put("OPTYPE", "20");
        params.put("MEMO", memo);
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(userTitle)) {
            params.put("USERID", userId);
            params.put("USERTITLE", userTitle);
            params.put("USERNAME", userName);
        }
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/product/accesslog", params, handler);
    }

    /**
     * 检查更新
     *
     * @param handler
     */
    public static void checkUpdate(int versionCode, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("ptype", Constants.PTYPE);
        params.put("vesionnum", versionCode);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/product/androiddowload", params, handler);
    }

    /**
     * 检查启动图 +
     *
     * @param handler
     */
    public static void checkStartScreen(String version, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("PTYPE", Constants.PTYPE);
        params.put("SSVERSION", version);
        ApiHttpClient.post2("https://wkzj.com/service/product/downloadstartscreen", params, handler);
    }

    /**
     * 获取上传信息
     *
     * @param handler
     */
    public static void getUploadInfo(AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.get("service/wkb/uploaddetail", handler);
    }

    /**
     * 获取video上传signature +++
     *
     * @param handler
     */
    public static void getVideoSignature(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/upload/videosignature2", params, handler);
        }
    }

    /**
     * 保存文件oss +++
     *
     * @param params
     * @param handler
     */
    public static void saveVideoFile(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/upload/savevideofile", params, handler);
        }
    }

    /**
     * 保存文件信息 +++
     *
     * @param params
     * @param handler
     */
    public static void saveVideo(String token, RequestParams params, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/wkb/savevideo", params, handler);
        }
    }

    /**
     * 保存文件信息 +++
     *
     * @param stringEntity
     * @param handler
     */
    public static void saveVideo(Context context, String token, StringEntity stringEntity, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            stringEntity.setContentEncoding("UTF-8");
            stringEntity.setContentType("text/xml;charset=utf-8");
            ApiHttpClient.post(context, "service/wkb/savevideo", stringEntity, handler);
        }
    }


    /**
     * 获取project上传signature +++
     *
     * @param handler
     */
    public static void getThumbSignature(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/upload/boardprojectthumbnailsignature", handler);
        }
    }

    public static void getCommonSignature(String token, String method, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/upload/" + method, handler);
        }
    }

    /**
     * 保存文件信息 +++
     *
     * @param stringEntity
     * @param handler
     */
    public static void saveResource(Context context, String token, StringEntity stringEntity,
                                    AsyncHttpResponseHandler handler) {
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            stringEntity.setContentEncoding("UTF-8");
            stringEntity.setContentType("text/xml;charset=utf-8");
            ApiHttpClient.post(context, "service/upload/saveresource", stringEntity, handler);
        }
    }

    /**
     * 已开启功能 +++
     */
    public static void funcs(String token, int userId, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            RequestParams params = new RequestParams();
            params.put("userId", userId);
            params.put("from", Constants.PTYPE);
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/userfunc", params, handler);
        }
    }

    /**
     * 保存书签 +++
     *
     * @param handler
     * @param params
     */
    public static void saveBookmark(String token, AsyncHttpResponseHandler handler, RequestParams params) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            params.setUseJsonStreamer(true);
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/savebookmark", params, handler);
        }

    }

    /**
     * 查询书签 +++
     *
     * @param handler
     */
    public static void queryBookmark(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            ApiHttpClient.post("service/wkb/getbookmark", handler);
        }
    }

    /**
     * 删除书签 +++
     *
     * @param handler
     */
    public static void deleteBookmark(String token, String bmid, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            RequestParams params = new RequestParams();
            params.put("BMID", bmid);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/wkb/deletebookmark", params, handler);
        }
    }

    /**
     * 发送短信验证码 +++   //type 10是注册 20是登录
     *
     * @param phoneNo
     * @param md5
     * @param handler
     * @param type
     */
    public static void sendSmsCode(String phoneNo, String md5, String type, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("phone", phoneNo);
        params.put("sign", md5);
        params.put("type", type);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/smscode", params, handler);
    }

    /**
     * 注册账号+++
     *
     * @param params
     * @param handler
     */
    public static void register(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/login/register", params, handler);
    }

    /**
     * 注册账号+++
     *
     * @param params
     * @param handler
     */
    public static void registerWithApiVersion(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setAPIVersion("1");
        ApiHttpClient.post("service/login/register", params, handler);
    }

    /**
     * 绑定极光推送
     *
     * @param handler
     */
    public static void jpushBind(String token, int userId, String registrationID, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        if (!StringUtils.isEmpty(token)) {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            RequestParams params = new RequestParams();
            //String registrationID = JPushInterface.getRegistrationID(AppContext.context());
            params.put("registrationid", registrationID);
            params.put("alias", userId);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/login/jpushbind", params, handler);
        }
    }

    /**
     * 第三方登录
     *
     * @param handler
     */
    public static void thirdpartylogin(String openid, final String type, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("openid", openid);
        params.put("type", type);
        params.put("from", Constants.PTYPE);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/thirdpartylogin", params, handler);
    }

    public static void getQQUnionid(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        String url = "https://graph.qq.com/oauth2.0/me?access_token=" + token + "&unionid=1";
        ApiHttpClient.get2(url, handler);
    }

    /**
     * 第三方登录-注册
     *
     * @param params
     * @param handler
     */
    public static void thirdpartyreg(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/login/thirdpartyreg", params, handler);
    }

    /**
     * 第三方登录-注册
     *
     * @param params
     * @param handler
     */
    public static void thirdpartyregWithApiVersion(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setAPIVersion("1");
        ApiHttpClient.post("service/login/thirdpartyreg", params, handler);
    }

    /**
     * 第三方登录-绑定
     *
     * @param params
     * @param handler
     */
    public static void thirdpartybind(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/login/thirdpartybind", params, handler);
    }


    /**
     * 检查登录状态
     *
     * @param handler
     */
    public static void checkLogin(String cookies, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        String url = "system/login/ajaxCheckLogin";
        ApiHttpClient.setCookie(cookies);
        ApiHttpClient.post(url, params, handler);
    }

    /**
     * 检查设备是否注册
     *
     * @param handler
     */
    public static void checkDeviceInfo(String serialNum, String productId, String appId, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("DEVICE_ID", appId);
        params.put("SERIAL_NUMBER", serialNum);
        params.put("PRODUCT_ID", productId);
        ApiHttpClient.post("service/product/checkdevice", params, handler);
    }

    /**
     * 注册设备
     *
     * @param sericalNum
     * @param handler
     */
    public static void registerDevice(String sericalNum, String appId, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("DEVICE_ID", appId);
        params.put("DEVICE_INFO", ApiClientHelper.getUserAgent());
        params.put("SERIAL_NUMBER", sericalNum);
        ApiHttpClient.post("service/product/register", params, handler);
    }

    /**
     * error log
     *
     * @param handler
     */
    public static void errorlog(String error, String appId, String version, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("OS", Constants.OSTYPE);
        params.put("OSVERSION", android.os.Build.VERSION.RELEASE);
        params.put("TERMINAL", android.os.Build.MANUFACTURER + " " + android.os.Build.MODEL);
        params.put("CPU", Build.CPU_ABI);
        params.put("APPVERSION", version);
        params.put("PTYPE", Constants.PTYPE);
        params.put("SN", appId);
        params.put("ERROR", error);
        ApiHttpClient.post("service/product/errorlog", params, handler);
    }

    /**
     * 获取购买客户信息
     *
     * @param handler
     */
    public static void getConsumerInfo(String appId, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("DEVICE_ID", appId);
        ApiHttpClient.post("service/product/getconsumerinfo", params, handler);
    }

    /**
     * 保存购买客户信息
     *
     * @param params
     * @param handler
     */
    public static void saveConsumerInfo(RequestParams params, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/product/saveconsumerinfo", params, handler);
    }


    /**
     * 班级列表
     *
     * @param handler
     */
    public static void classList(String token, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/classes/simplelist", handler);
    }

    /**
     * 班级成员
     *
     * @param clsid
     * @param handler
     */
    public static void classMember(String token, String clsid, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("clsid", clsid);
        params.put("type", "1");
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/wkb/studentlist", params, handler);
    }

    /**
     * 题库
     *
     * @param handler
     */
    public static void questionList(String token, int start, AsyncHttpResponseHandler handler) {
        //LoginUserBean loginUserBean = AppContext.getLoginUserBean();
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("type", "01,02");
        params.put("start", start);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/profile/questions", params, handler);
    }

    /**
     * apiVersion = 1 的题库
     *
     * @param handler
     */
    public static void questionListWithApiVersion(String token
            , int start
            , String questkindid
            , String keyword
            , String type
            , AsyncHttpResponseHandler handler) {
        ApiHttpClient.setAPIVersion("1");
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("questkindid", questkindid);
        params.put("keyword", keyword);
        params.put("start", start);
        params.put("type", type);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/profile/questions", params, handler);
    }

    public static void getUsersig(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/live/getusersig", handler);
    }

    public static void setsilence(String token, int livePushID, String silence, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("lcid", livePushID);
        params.put("silence", silence);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/live/setsilence", params, handler);
    }

    public static void getsilence(String token, int livePushID, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("lcid", livePushID);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/live/getsilence", params, handler);
    }

    public static void setmic(String token, int livePushID, String micstatus, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("lcid", livePushID);
        params.put("status", micstatus);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/live/setmic", params, handler);
    }

    public static void getMemberList(String token, int clzzId, int start, int pageSize, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        ApiHttpClient.setAPIVersion("1");
        RequestParams params = new RequestParams();
        params.put("clsid", clzzId);
        params.put("start", start);
        params.put("pagesize", pageSize);
        params.put("usertype", "50");
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/memberlist", params, handler);
    }

    public static void getGroupList(String token, int clzzId, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        ApiHttpClient.setAPIVersion("1");
        RequestParams params = new RequestParams();
        params.put("clsid", clzzId);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/grouplist", params, handler);
    }

    public static void getRuleList(String token, int clzzId, String type, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("clsid", clzzId);
        if (type != null) {
            params.put("type", type);
        }
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/rulelist", params, handler);
    }

    public static void deleteRule(Context context, String token, String json, AsyncHttpResponseHandler handler) throws Exception {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        StringEntity stringEntity = new StringEntity(json, "utf-8");
        stringEntity.setContentEncoding("UTF-8");
        stringEntity.setContentType("text/xml;charset=utf-8");
        ApiHttpClient.post(context, "service/classes/deleterule", stringEntity, handler);
    }

    public static void iconList(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/classes/iconlist", handler);
    }

    public static void createRule(String token, String ruleName, int score, String type, int clazzId, String icon, String ruleType, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("rulename", ruleName);
        params.put("score", score);
        params.put("type", type);
        params.put("clsid", clazzId);
        params.put("icon", icon);
        params.put("ruletype", ruleType);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/createrule", params, handler);
    }

    public static void remark(Context context, String token, String json, AsyncHttpResponseHandler handler) throws Exception {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        StringEntity stringEntity = new StringEntity(json, "utf-8");
        stringEntity.setContentEncoding("UTF-8");
        stringEntity.setContentType("text/xml;charset=utf-8");
        ApiHttpClient.post(context, "service/classes/remark", stringEntity, handler);
    }

    public static void saveData(Context context, String token, String url, String json, AsyncHttpResponseHandler handler) throws Exception {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        String s = new String(json.getBytes("utf-8"));
        StringEntity stringEntity = new StringEntity(s, "utf-8");
        stringEntity.setContentEncoding("UTF-8");
        stringEntity.setContentType("text/xml;charset=utf-8");
        ApiHttpClient.post(context, url, stringEntity, handler);
    }

    public static void synchronize(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.setAPIVersion("1");
        ApiHttpClient.post("service/classes/synchronize", handler);
    }

    /**
     * 检查登录状态
     *
     * @param handler
     */
    public static void isLogin(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/login/check", params, handler);
    }

    /**
     * 检查PPT转码状态
     *
     * @param token
     * @param resid
     * @param handler
     */
    public static void pptconvertstate(String token, String resid, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("resid", resid);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/wkb/pptconvertstate", params, handler);
    }

    /**
     * 检查账号登录类型
     *
     * @param usertitle
     * @param key
     * @param handler
     */
    public static void checkLoginType(String usertitle, String key, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("usertitle", usertitle);
        params.put("key", key);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/checkusertitle", params, handler);
    }


    /**
     * 验证码登录
     *
     * @param phone
     * @param smsCode
     * @param handler
     */
    public static void smsLogin(String phone, String smsCode, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("phone", phone);
        params.put("code", smsCode);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/smscodelogin", params, handler);
    }


    /**
     * 短信验证码找回密码
     *
     * @param phone
     * @param sign
     * @param handler
     */
    public static void smsFindPassword(String phone, String sign, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("phone", phone);
        params.put("sign", sign);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/smscodefindpassword", params, handler);
    }

    /**
     * 验证找回密码的验证码
     *
     * @param phone
     * @param smsCode
     * @param handler
     */
    public static void verifyFindPasswordSmsCode(String phone, String smsCode, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("phone", phone);
        params.put("smscode", smsCode);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/findpassword", params, handler);
    }

    /**
     * 重置密码
     *
     * @param phone
     * @param pwd
     * @param sign
     * @param handler
     */
    public static void resetPassword(String phone, String pwd, String sign, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("phone", phone);
        params.put("password", pwd);
        params.put("sign", sign);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/login/findpasswordreset", params, handler);
    }

    /**
     * 获取启动页广告
     *
     * @param handler
     */
    public static void getLaunchAd(AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/advertising/launchadvertising", handler);
    }

    /**
     * 获取首页弹窗
     *
     * @param handler
     */
    public static void getMainPopAd(AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.post("service/advertising/popupadvertising", handler);
    }

    /**
     * 广告点击统计
     *
     * @param handler
     */
    public static void adClickCollect(String token, String adid, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("adid", adid);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/advertising/clickadvertising", params, handler);
    }

    /**
     * 广告分享统计
     * // 10-微信好友 20-微信朋友圈 30-QQ好友 40-QQ空间 50-复制链接
     *
     * @param handler
     */
    public static void adShareCollect(String token, String logid, String shareType, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("logid", logid);
        params.put("shareType", shareType);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/advertising/dealshare", params, handler);
    }


    /**
     * 获取邀请注册参数
     *
     * @param handler
     */
    public static void getRegisterInvite(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/profile/registerinvite", handler);
    }

    /**
     * 购买vip
     */
    public static void getVipPay(String token, String productno, String paytype, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("productno", productno);
        params.put("paytype", paytype);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/vipuser/getorder", params, handler);
    }


    /**
     * 购买vip
     */
    public static void getVipDetail(AsyncHttpResponseHandler handler) {
        ApiHttpClient.setAPIVersion("1");
        ApiHttpClient.post("service/vipuser/detail", handler);
    }

    public static void syncTest(String token, int questionid, String uuid,
                                int clsid, String starttime,
                                String endtime, int studentnum,
                                int submitnum, int correctnum,
                                String answer, String correct, String examuuid,
                                AsyncHttpResponseHandler handler) {
        try {
            ApiHttpClient.removeAPIVersion();
            ApiHttpClient.setToken(token);
            RequestParams params = new RequestParams();
            params.put("questionid", questionid);
            params.put("uuid", uuid);
            params.put("clsid", clsid);
            params.put("starttime", starttime);
            params.put("endtime", endtime);
            params.put("studentnum", studentnum);
            params.put("submitnum", submitnum);
            params.put("correctnum", correctnum);
            params.put("questionanswer", correct);
            params.put("answer", new JSONArray(answer));
            params.put("examuuid", examuuid);
            params.setUseJsonStreamer(true);
            ApiHttpClient.post("service/quiz/synchronize", params, handler);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    /**
     * 创建班级
     *
     * @param token
     * @param classname
     * @param gradedesc
     * @param subjectdesc
     * @param handler
     */
    public static void createClass(String token, String classname, String gradedesc, String subjectdesc, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("classname", classname);
        params.put("gradedesc", gradedesc);
        params.put("subjectdesc", subjectdesc);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/create", params, handler);
    }

    /**
     * 加入班级
     *
     * @param token
     * @param subjectdesc
     * @param handler
     */
    public static void joinClass(String token, String classid, String subjectdesc, String followflag, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("classid", classid);
        params.put("subjectdesc", subjectdesc);
        params.put("followflag", followflag);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/join", params, handler);
    }


    /**
     * 搜索班级
     *
     * @param token
     * @param handler
     */
    public static void getClasssSearchList(String token, String keyword, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("keyword", keyword);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/classes/search", params, handler);
    }

    /**
     * 获取班级列表
     *
     * @param token
     * @param handler
     */
    public static void getClasssSimpleList(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/classes/simplelist", handler);
    }

    public static void bingCard(String token, String userid, String cardid,
                                AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        //ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("userid", userid);
        params.put("cardid", cardid);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/wkb/bindcard", params, handler);
    }

    /**
     * 激活码兑换
     *
     * @param actcode
     * @param clientid
     * @param handler
     */
    public static void redeemCode(String actcode, String clientid, AsyncHttpResponseHandler handler) {
        ApiHttpClient.removeAPIVersion();
        RequestParams params = new RequestParams();
        params.put("actcode", actcode);
        params.put("clientid", clientid);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/vipuser/activate", params, handler);
    }

    public static void createPaper(String token, String title, String uuid, int clsid,
                                   String starttime, String endtime, int studentnum,
                                   int submitnum, int correctnum, int quiznum, AsyncHttpResponseHandler handler) {

        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("title", title);
        params.put("uuid", uuid);
        params.put("clsid", clsid);
        params.put("starttime", starttime);
        params.put("endtime", endtime);
        params.put("studentnum", studentnum);
        params.put("submitnum", submitnum);
        params.put("correctnum", correctnum);
        params.put("quiznum", quiznum);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/quiz/createexam", params, handler);
    }

    public static void checkStorage(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/upload/checkstoragebeforeupload", handler);
    }

    public static void getMessages(AsyncHttpResponseHandler handler) {
        ApiHttpClient.post("service/advertising/getwkbactivitylist", handler);
    }

    public static void getAdShareParameters(String token, String messageId, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("activityid", messageId);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/advertising/getsharedinfo", params, handler);
    }

    public static void checkSendVipAdShow(AsyncHttpResponseHandler handler) {
        ApiHttpClient.post("service/timer/showInviteActivty", handler);
    }

    public static void checkHasNewAd(String token, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        ApiHttpClient.post("service/advertising/wkbActivityUnreadState", handler);
    }

    public static void trackingEvent(String token, String recorduuid, String objuuid, int clsid,
                                     String subjectdesc, String opetime, String actionid,
                                     Object extradata, AsyncHttpResponseHandler handler) {
        ApiHttpClient.setToken(token);
        RequestParams params = new RequestParams();
        params.put("recorduuid", recorduuid);
        params.put("objuuid", objuuid);
        params.put("clsid", clsid);
//        params.put("subjectdesc", subjectdesc);
        params.put("opetime", opetime);
        params.put("actionid", actionid);
        params.put("extradata", extradata == null ? "" : extradata);
        params.setUseJsonStreamer(true);
        ApiHttpClient.post("service/eventtracking/trackingevent", params, handler);
    }
}
