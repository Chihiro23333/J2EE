const unCheckTaoCan = "taocan";
const checkTaoCan = "taocan_active";

addLoadEvent(init);
addLoadEvent(addToogleTaoCan);
addLoadEvent(addSubmitAction);
addLoadEvent(checkFirst);

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
    var html = document.getElementsByTagName('html');
    html[0].style.fontSize = document.body.offsetWidth/7.5+"px";
}

function addToogleTaoCan(){
    var li = document.getElementsByTagName("li");
    if(!li) return false;
    clearCheck();
    for(var i = 0; i < li.length; i++){
        var item = li[i];
        item.onclick = function(){
            clearCheck();
            this.className = checkTaoCan;
            return true;
        }
    }
}

function addSubmitAction(){
    var submit = document.getElementById("submit");
    if(!submit) return false;
    submit.onclick = function(){
        window.location = "unicom.html?taocan="+getCurCheckName();
    }
}

function checkFirst(){
    var li = document.getElementsByTagName("li");
    if(!li) return false;
    for(var i = 0; i < li.length; i++){
        var item = li[i];
        if(i == 0){
            item.className = checkTaoCan;
        }else{
            item.className = unCheckTaoCan;
        }
       
    }
}

function getCurCheckName(){
    var li = document.getElementsByTagName("li");
    if(!li) return false;
    for(var i = 0; i < li.length; i++){
        var item = li[i];
        if( item.className == checkTaoCan){
            return item.getAttribute("name");
        }
       
    }
}

function clearCheck(){
    var li = document.getElementsByTagName("li");
    if(!li) return false;
    for(var i = 0; i < li.length; i++){
        var item = li[i];
        item.className = unCheckTaoCan;
    }
}
