package com.example.flutter_dmcb_alibc;

import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.alibaba.alibclogin.AlibcLogin;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.randy.alibcextend.auth.AuthCallback;
import com.randy.alibcextend.auth.TopAuth;

import java.util.Map;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;

public class CustomActivity extends AppCompatActivity {

    private int mResumeIndex = 0;

    private static MethodChannel.Result mResult;

    private static MethodCall mMethodCall;

    public static void setCallBack(MethodCall methodCall, MethodChannel.Result result) {
        mMethodCall = methodCall;
        mResult = result;
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String method = getIntent().getStringExtra("method");
        if ("authLogin".equals(method)) {
            authLogin();
        }
        this.setFinishOnTouchOutside(true);
    }


    /**
     * 申请淘宝授权登录
     */
    public void authLogin() {
        String appKey = mMethodCall.argument("appKey");
        String appName = mMethodCall.argument("appName");
        String appLogo = mMethodCall.argument("appLogo");
        TopAuth.showAuthDialog(CustomActivity.this, R.mipmap.ic_launcher, appName, appKey, new AuthCallback() {
            @Override
            public void onSuccess(String token, String s) {
                Map<String, Object> map = AlibcLogin.getInstance().getUserInfo();
                Log.d("substring", " getUserInfo " + JSON.toJSONString(map));
                JSONObject mJSONObject = new JSONObject();
                mJSONObject.put("nick", map.get("nick"));
                mJSONObject.put("avatarUrl", "");
                mJSONObject.put("openId", map.get("userId"));
                mJSONObject.put("openSid", "");
                mJSONObject.put("topAccessToken", token);
                mJSONObject.put("topAuthCode", "");
                mJSONObject.put("expiresIn", s);

                JSONObject main = new JSONObject();
                main.put("code", "00000");
                main.put("message", "授权成功");
                main.put("payload", mJSONObject);

                mResult.success(main);
                Log.d("substring", "授权成功 " + JSON.toJSONString(main));
                runOnUiThread(() -> {
                    finish();
                    overridePendingTransition(R.anim.triver_fade_in, R.anim.triver_fade_out);
                });
            }

            @Override
            public void onError(String s, String s1) {
                Log.d("substring", "授权失败 " + s + s1);
                JSONObject main = new JSONObject();
                main.put("code", s1);
                main.put("message", s);
                main.put("payload", "");
                mResult.success(main);
                runOnUiThread(() -> {
                    finish();
                    overridePendingTransition(R.anim.triver_fade_in, R.anim.triver_fade_out);
                });
            }
        });
    }

    @Override
    protected void onResume() {
        mResumeIndex++;
        super.onResume();
        if (mResumeIndex > 1) {
            finish();
        }
    }

    @Override
    public void onBackPressed() {
        Log.d("substring", "onBackPressed");
        super.onBackPressed();
    }

    @Override
    protected void onDestroy() {
        mResult = null;
        mMethodCall = null;
        super.onDestroy();
    }
}
