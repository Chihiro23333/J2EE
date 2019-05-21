function dispalyAbbr(){
    var abbrlist = document.getElementsByTagName("abbr");
    if(abbrlist.length < 1) return false;
    var array = new Array();
    for(var i = 0; i< abbrlist.length; i++){
        var title = abbrlist[i].getAttribute("title");
        var value = abbrlist[i].firstChild.nodeValue;
        array[title] = value;
    }

    var dl = document.createElement("dl");
    for ( var key in array) {
        var dd = document.createElement("dd");
        var ddText = document.createTextNode(key);
        var dt = document.createElement("dt");
        var dtText = document.createTextNode(array[key]);
        
        dd.appendChild(ddText);
        dt.appendChild(dtText);

        dl.appendChild(dt);
        dl.appendChild(dd);
    }

    var h2 = document.createElement("h2");
    var h2Text = document.createTextNode("Abbr tag in HTML")
    h2.appendChild(h2Text);

    document.body.appendChild(h2);
    document.body.appendChild(dl);
}

window.onload = dispalyAbbr;