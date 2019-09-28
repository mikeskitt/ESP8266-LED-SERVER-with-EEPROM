String web_page = "";
void setWebpage() {
  web_page = "Content-Type: text/html;charset=UTF-8";
  web_page = "<HTML>\n<HEAD>";
  web_page = "</HEAD><BODY>";
  web_page = "<h1>Neopixel Control interface V1.1</h1><p><h2>Brightness</h2>";
  web_page += " <form action=\"/led\" method=get>";
  web_page += "     <select name=\"Lum\">";
  web_page += "         <option value=\"0\">0%</option>";
  web_page += "         <option selected value=\"64\">25%</option>"; // valeur par defaut
  web_page += "         <option value=\"127\">50%</option>";
  web_page += "         <option value=\"191\">75%</option>";
  web_page += "         <option value=\"255\">100%</option>";
  web_page += "     </select>";
  web_page += " </p>";
  web_page += " <p>";
  web_page += " <h2>Select light effect (100 = demo, 0..43)</h2>";
  web_page += " <input type=\"number\" name=\"effet\" maxlength=\"3\" size=\"6\" /><br />";
  web_page += " </p>";
  web_page += "<br><input type=\"submit\" value=\"Send\" /></form>";
  web_page += "</BODY></HTML>";
}
