
addLoadEvent(init);

function init(){
    let htmlwidth = document.body.clientWidth ;  //浏览器兼容
    var html = document.getElementsByTagName('html');
    html[0].style.fontSize =htmlwidth/6+"px";
}

function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}