function addLoadEvent(func){
    var oldLoad = window.onload;
    if(typeof oldLoad != "function"){
        window.onload = func;
    }else{
        oldLoad();
        func();
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

function insertAfter(newElement, targetElment){
    var parent = targetElment.parentNode;
    if(parent.lastChild == targetElment){
        parent.appendChild(newElement);
    }else{
        parent.insertBefore(newElement, targetElment.nextSibling);
    }
}

addLoadEvent(highLightPage);
addLoadEvent(prepareInternalnav);
addLoadEvent(prepareGllary);
addLoadEvent(createPlaceHolder);
addLoadEvent(styleTrByClassCss);

function highLightPage(){
    var header = document.getElementsByTagName("header");
    if(header.length == 0) return false;
    var nav = header[0].getElementsByTagName("nav");
    if(nav.length == 0) return false;
    var links = nav[0].getElementsByTagName("a");
    if(links.length == 0) return false;
    for(var i =0; i< links.length; i++){
        var curLink = links[i];
        if(window.location.href.indexOf(curLink) != -1){
            curLink.className = "here";
            var linkText = curLink.lastChild.nodeValue.toLowerCase();
            document.body.setAttribute("id",linkText);
        }
    }
}

function prepareInternalnav(){
    var article = document.getElementsByTagName("article");
    if(article.length == 0) return false;
    var nav = article[0].getElementsByTagName("nav");
    if(nav.length == 0) return false;
    var a = nav[0].getElementsByTagName("a");
    if(a.length == 0)  return false;
    for(var i = 0; i< a.length; i++){
        var curLik = a[i];
        var sectionId = curLik.getAttribute("href").split("#")[1];
        curLik.sectionId = sectionId;
        document.getElementById(sectionId).style.display = "none";
        curLik.onclick = function(){
            showSection(this.sectionId);
            return false;
        }
    }
}

function showSection(sectionId){
    var section = document.getElementsByTagName("section");
    if(section.length == 0) return false;
    for(var i = 0; i < section.length; i++){
        if(section[i].getAttribute("id") == sectionId){
            section[i].style.display = "block";
        }else{
            section[i].style.display = "none";
        }
    }
}

function showPic(whichPic){
    if(!document.getElementById("placeholder"))return false;
    var img = whichPic.getElementsByTagName("img");
    var href = img[0].getAttribute("src");
    var placeholder = document.getElementById("placeholder");
    placeholder.setAttribute("src",href);

    if(document.getElementById("description")){
        var description  = document.getElementById("description");
        var title = whichPic.getAttribute("title");
        description.firstChild.nodeValue = title;
    }
    return true;
}

function createPlaceHolder(){
    if(!document.getElementById("imagegallery"))return false;
    var img = document.createElement("img");
    img.setAttribute("src","images/girl1.jpg");
    img.setAttribute("id","placeholder");
    img.setAttribute("width","400px");
    img.setAttribute("height","400px");

    var pNode = document.createElement("p");
    pNode.setAttribute("id","description");
    var txt1 = document.createTextNode("Choose a image");
    pNode.appendChild(txt1);

    insertAfter(img,document.getElementById("imagegallery"));
}

function prepareGllary(){
    if(!document.getElementsByTagName)return false;
    if(!document.getElementById) return false;
    if(!document.getElementById("imagegallery"))return false;
    var gllary = document.getElementById("imagegallery");
    var links = gllary.getElementsByTagName("a");
    for(var i = 0; i < links.length; i++){
            links[i].onclick = function(){
                return !showPic(this);
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
                addClass(curTr, "colorTr");
                odd = false;
            }else{
                addClass(curTr, "noColorTr");
                odd = true;
            }
        }
    }
}