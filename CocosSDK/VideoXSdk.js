function initSdk() {

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"initAdsSDK");
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "initAdSdk", "()V");
    }
    
}

function showSplashAd(slotId){
if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"showSplashAd:",slotId);
    }else{
        // jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "loadInterstitialAd", "(Ljava/lang/String;)V", slotId);
    }

}

function loadInterstitialAd(slotId) {

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"loadInterstitialAds:",slotId);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "loadInterstitialAd", "(Ljava/lang/String;)V", slotId);
    }
    
}

function isInterstitialAdReady(slotId) {

    if(cc.sys.OS_IOS == cc.sys.os){
        var ret = jsb.reflection.callStaticMethod('VXJSToNative',"interstitialAdsReady:",slotId);
        return ret;
    }else{
        var ret = jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "isInterstitialAdReady", "(Ljava/lang/String;)Z", slotId);
        return ret;
    }
    
}

function showInterstitialAd(slotId) {

    if (!isInterstitialAdReady(slotId)) {
        showToast("广告没有准备好");
        return;
    }

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"playInterstitialAds:",slotId);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "showInterstitialAd", "(Ljava/lang/String;)V", slotId);
    }
    
}


function loadRewardAd(slotId) {

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"loadRewardsAds:",slotId);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "loadRewardAd", "(Ljava/lang/String;)V", slotId);
    }
    
}

function isRewardAdReady(slotId) {

    if(cc.sys.OS_IOS == cc.sys.os){
        var ret = jsb.reflection.callStaticMethod('VXJSToNative',"rewardsAdsReady:",slotId);
        return ret;
    }else{
        var ret = jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "isRewardAdReady", "(Ljava/lang/String;)Z", slotId);
        return ret;
    }

    
}

function showRewardAd(slotId) {

    if (!isRewardAdReady(slotId)) {
        showToast("广告没有准备好");
        return;
    }


    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"playRewardsAds:",slotId);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "showRewardlAd", "(Ljava/lang/String;)V", slotId);
    }

    
}


function showBannerAd(slotId) {

    console.log("showBannerAd");

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"showBannerAds:",slotId);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "loadBannerAd", "(Ljava/lang/String;)V", slotId);
    }

    
}


function sendEvent(action, label, value, extra, eid) {

    console.log("sendEvent");

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXReporter',"trackEvent:action:label:value:eid:extra:","DCGAds",action,label,value,extra,eid);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "sendEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", action, label, value, extra, eid);
    }
    
}


// ---------------------------- CallBack --------------------------

//-------- interstital ad

function onInterstitialAdLoadSuccess(slotId){

    // showToast("插屏加载成功");
}

function onInterstitialAdLoadError(slotId, error){
    //do something
    // showToast("插屏加载失败:"+error);
}

function onInterstitialAdOpen(slotId){
    //do something
    // showToast("插屏已经打开");
}

function onInterstitialAdClose(slotId){
    //do something
    // showToast("插屏播放完成");
}

function onInterstitialAdClick(slotId){
    //do something
    // showToast("插屏广告被点击");
}

//-------- reward ad

function onRewardAdLoadSuccess(slotId){
    //do something
    // showToast("激励视频加载完成");
}

function onRewardAdLoadError(slotId, error){
    //do something
    // showToast("激励视频加载失败:"+error);
}

function onRewardAdLoadOnShow(slotId){
    //do something
    // showToast("激励视频开始播放");

}

function onRewardAdLoadOnClose(slotId, shouldReward){
    //do something
    // showToast("激励视频播放完成，激励状态"+shouldReward);

}

function onRewardAdLoadOnShowError(slotId, error){
    //do something
    // showToast("激励视频播放失败:"+error);

}

function onRewardAdLoadClick(slotId){
    //do something
    // showToast("激励视频被点击");

}

//-------- banner ad
function onBannerAdLoad(slotId){
    //do something
    // showToast("横幅广告加载");

}

function onBannerAdShowError(error){
    //do something
    // showToast("横幅广告展示失败:"+error);

}

function onBannerAdDidClosed(){
    //do something
    // showToast("横幅广告已经关闭");

}

function bannerAdDidClicked(){

    // showToast("横幅广告被点击");
}

//-------- splash ad

function splashAdDidLoad(){

    // showToast("开屏广告已经被加载");
}

function splashAdDidClick(){
   // showToast("开屏广告已经被点击");
}

function splashAdWillShow(){
    // showToast("开屏广告即将展示");
}

function splashAdDidClose(){
    // showToast("开屏广告已经关闭");
}

function splashAdDidFailWithError(error){
    // showToast("开屏广告展示失败:"+error);
}

// test code

function showToast(msg) {

    if(cc.sys.OS_IOS == cc.sys.os){
        jsb.reflection.callStaticMethod('VXJSToNative',"showToast:",msg);
    }else{
        jsb.reflection.callStaticMethod("org/cocos2dx/javascript/SdkBridge", "ShowToast", "(Ljava/lang/String;)V", msg);
    }
    
}