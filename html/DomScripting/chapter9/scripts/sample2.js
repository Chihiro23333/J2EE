function styleSample(){
    var table = document.getElementsByTagName("table");
    var tr,odd;
    for(var i = 0 ; i < table.length ; i++){
        var curTable = table[i];
        tr = curTable.getElementsByTagName("tr");
        for(var j = 0; j < tr.length; j++){
            var curTr = tr[j];
            if(odd){
                curTr.style.background = "#699";
                odd = false;
            }else{
                odd = true;
            }
        }
    }
}

function styleTrByClassCss(){
    var table = document.getElementsByTagName("table");
    var tr,odd;
    for(var i = 0 ; i < table.length ; i++){
        var curTable = table[i];
        tr = curTable.getElementsByTagName("tr");
        for(var j = 0; j < tr.length; j++){
            var curTr = tr[j];
            if(odd){
                addClass(curTr, "intro");
                odd = false;
            }else{
                odd = true;
            }
        }
    }
}


function addClass(element, value){
    if(!element.className){
        element.className = value;
    }else{
        var oldClassName = element.className;
        var newClassName = oldClassName;
        newClassName += " ";
        newClassName += value;
        element.className = newClassName;
    }
}

function hightLightTr(){
    var tr = document.getElementsByTagName("tr");
    for (var i = 0; i < tr.length; i++) {
        var element = tr[i];
        element.onmouseover = function(){
            this.style.fontWeight = "bold";
        }
        element.onmouseout = function(){
            this.style.fontWeight = "normal";
        }
    }
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

addLoadEvent(styleTrByClassCss);
addLoadEvent(hightLightTr);
