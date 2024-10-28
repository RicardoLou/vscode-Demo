function autoLogin() {
    var username = document.getElementById("username"); // 获取用户名输入框
    var password = document.getElementById("password"); // 获取密码输入框
    var loginButton = document.getElementById("btn-login"); // 获取登录按钮

    username.value = "02703227986"; // 设置用户名
    password.value = "227986"; // 设置密码
    loginButton.click();
}