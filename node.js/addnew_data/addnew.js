const express = require('express');
const app = express();
app.listen(8181);
const fs = require('fs');

app.use((req,res,next)=>{
    res.setHeader('Content-Type','text/html; charset=UTF-8');
    next();
});

app.get('/Addnewdata',(req ,res) =>{
    let data = 'Name:'+req.query.name+","+"jobs:"+req.query.jobs+","+"habbit:"+req.query.habbit+","+"date:"+req.query.date+","+"age:"+req.query.age+","+"employeeno:"+req.query.employeeno+"\n";
    fs.appendFile('data.csv',data,(err) =>{
            if (err) throw err;
            console.log('appended!!');
        });
    res.end('saved!!!');
});