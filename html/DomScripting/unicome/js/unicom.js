addLoadEvent(init);
addLoadEvent(getParams);


function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}


function init(){
    let htmlwidth = document.body.clientWidth ;  //浏览器兼容
    var html = document.getElementsByTagName('html');
    html[0].style.fontSize =htmlwidth/6+"px";
}


function getParams(){
    var params = window.location.search;
    var paramsArr =  params.substring(1,params.length).split("&");
    if(!paramsArr || paramsArr.length == 0) return false;
    var form = document.getElementsByTagName("form")[0];
    for(var i = 0; i < paramsArr.length; i++){
        var query = paramsArr[i];
        var queryDetail = query.split("=");
        console.log(queryDetail);
        var input = document.createElement("input");
        input.setAttribute("name",queryDetail[0]);
        input.setAttribute("value",queryDetail[1]);
        input.setAttribute("type","hidden");
        form.appendChild(input);
    }
}
