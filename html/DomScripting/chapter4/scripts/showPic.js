function showPic(whichPic){
    var href = whichPic.getAttribute("href");
    var placeholder = document.getElementById("placeholder");
    placeholder.setAttribute("src",href);

    var title = whichPic.getAttribute("title");
    var description  = document.getElementById("description");
    description.firstChild.nodeValue = title;
   
}

function countBodyChildren(){
    var body_element = document.getElementsByTagName("body");
    alert(body_element[0].childNodes.length);
}

// window.onload = countBodyChildren;

addLoadEvent(prepareGllary);

function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
    }
}

function prepareGllary(){
    if(!document.getElementsByTagName)return false;
    if(!document.getElementById) return false;
    if(!document.getElementById("gllary"))return false;
    var gllary = document.getElementById("gllary");
    var links = gllary.getElementsByTagName("a");
    for(var i = 0; i < links.length; i++){
            links[i].onclick = function(){
                showPic(this);
                return false;
        }
    }
}

function popUp(url){
    window.open(url,"popUp","width=800,height=480");
}

