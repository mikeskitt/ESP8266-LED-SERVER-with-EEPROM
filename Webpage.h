
String web_page = "";
void setWebpage() {
  web_page = "Content-Type: text/html;charset=UTF-8";
  web_page = "<HTML>\n<HEAD>";
  web_page = "</HEAD><BODY>";
  web_page += "<h1>" + String(LOCATION) + " Light Control </h1><p><h2>Brightness</h2>";
  web_page += " <form action=\"/led\" method=get>";
  web_page += "     <select name=\"Lum\">";
  web_page += "         <option selected value=\"\"></option>";
  web_page += "         <option value=\"0\">Off</option>";
  web_page += "         <option value=\"64\">25%</option>";
  web_page += "         <option value=\"127\">50%</option>";
  web_page += "         <option value=\"191\">75%</option>";
  web_page += "         <option value=\"255\">100%</option>";
  web_page += "     </select>";
  web_page += " </p><p><h2>Programme</h2>";
  web_page += "     <select name=\"Prog\">";
  web_page += "         <option value=\"0\">0</option>";
  web_page += "         <option selected value=\"1\">Twinkles</option>";
  web_page += "         <option value=\"2\">2</option>";
  web_page += "         <option value=\"3\">3</option>";
  web_page += "         <option value=\"4\">4</option>";
  web_page += "     </select>";
  web_page += " </p>";
  web_page += " <p>";
  web_page += " <h2>Select palette (0-11)</h2>";
  web_page += " <input type=\"number\" name=\"effet\" maxlength=\"3\" size=\"6\" /><br />";
  web_page += " </p>";
  web_page += " <p>";
  web_page += " <h2>Select Speed(0-8)</h2>";
  web_page += " <input type=\"number\" name=\"speed\" maxlength=\"2\" size=\"3\" /><br />";
  web_page += " </p>";
  web_page += "<br><input type=\"submit\" value=\"Send\" /></form>";
  web_page += "</BODY></HTML>";
}
