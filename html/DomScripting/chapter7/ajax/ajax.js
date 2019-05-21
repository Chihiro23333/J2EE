window.onload = function(){
    var httpObject = getHttpObject();
    if(httpObject){
        httpObject.open("GET","ajax.txt",true);
        httpObject.onreadystatechange = function(){
            if(httpObject.readyState == 4){
                var para = document.getElementById("testdiv");
                var txt = document.createTextNode(httpObject.responseText);
                para.appendChild(txt);
            }
        }
        httpObject.send(null);
    }
}

function getHttpObject(){
    if(typeof XMLHttpRequest == "undefined"){
        XMLHttpRequest = function(){
            try{
                return new ActiveXObject("Msxml2.XMLHTTP.6.0");
            }catch(e){}
            try{
                return new ActiveXObject("Msxml2.XMLHTTP.3.0");
            }catch(e){}
            try{
                return new ActiveXObject("Msxml2.XMLHTTP");
            }catch(e){}
            return false;
        }
        
    }
    return new XMLHttpRequest();
}