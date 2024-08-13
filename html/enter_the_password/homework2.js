document.getElementById("Username").addEventListener("blur", checkN);
function checkN() {
  let Username = document.getElementById("Username");
  let UnameV = Username.value;
  let UnameLen = UnameV.length;
  let s1 = document.getElementById("s1");
  let flag = false;
  if (UnameV == "") {
    s1.innerHTML = `不可為空白`;
  } else if (UnameLen >= 2) {
    for (let i = 0; i <= UnameLen; i++) {
      let UnameVC = UnameV.charCodeAt(i);
      if (UnameVC > 0x9fff || UnameVC < 0x4e00) {
        s1.innerHTML = `請輸入中文`;
        flag = false;
        break;
      } else {
        flag = true;
      }
    }
  } else {
    s1.innerHTML = `請輸入至少兩個字`;
  }
  if (flag) {
    s1.innerHTML = "輸入正確";
  }
}
document.getElementById("Password").addEventListener("blur", checkP);
function checkP() {
  let Password = document.getElementById("Password");
  let PasswV = Password.value;
  let PasswLen = PasswV.length;
  let s2 = document.getElementById("s2");
  let flag = false,
    flag1 = false,
    flag2 = false;
  if (PasswV == "") {
    s2.innerHTML = `不可為空白`;
  } else if (PasswLen >= 6) {
    for (let i = 0; i < PasswLen; i++) {
      let ch = PasswV.charAt(i).toUpperCase();
      if (ch >= "A" && ch <= "Z") flag = true;
      else if (ch >= "0" && ch <= "9") flag1 = true;
      if (ch >= 0x0000 && ch <= 0x4dff) flag2 = true;
      console.log(flag2, flag1, flag);
      if (flag && flag1 && flag2) break;
    }
    if (flag && flag1 && flag2) s2.innerHTML = "輸入正確";
    else s2.innerHTML = "請輸入至少一個英文或數字或特殊符號";
  } else {
    s2.innerHTML = "請至少輸入六個數字或英文";
  }
}
document.getElementById("date").addEventListener("blur", checkD);
function checkD() {
  let DateN = document.getElementById("date");
  let DateV = DateN.value;
  let NDate = new Date(DateV);
  let NDD = NDate.getDate();
  let flag = false,
    flag1 = false;
  function DateFormattest(dateString) {
    const checkI = /^\d{4}\/\d{2}\/\d{2}$/;
    return checkI.test(dateString);
  }
  console.log(NDD)
  console.log(DateV.charAt(8) + DateV.charAt(9))
  if (NDD != DateV.charAt(8) + DateV.charAt(9)) {
    s3.innerHTML = "請輸入有效日期";
  } else {
    flag = true;
  }
  if (!DateFormattest(DateV)) {
    s3.innerHTML = `請輸入有效格式 YYYY/MM/DD`;
  } else {
    flag1 = true;
  }
  if (flag && flag1) s3.innerHTML = "輸入正確";
  if (DateV == "") {
    s3.innerHTML = "不可為空白";
  }
}
