package com.example.flutter_dmcb_alibc;

import android.app.Application;

import androidx.multidex.MultiDex;

public class App extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        MultiDex.install(this);
    }
}
