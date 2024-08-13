const express = require('express');
const app = express();
app.listen(8181);
const fs = require('fs');

app.set('view engine','ejs');
const csvToJson = require('convert-csv-to-json');
const { Parser } = require('json2csv');

app.use((req,res,next)=>{
    json=csvToJson.fieldDelimiter(',').getJsonFromCsv("./employee.csv");
    res.setHeader('Access-Control-Allow-Origin','*');
    next();
});

app.get('/employee/getall',(req,res)=>{
    res.send(json);
});

app.get('/employee/getone',(req,res)=>{
    let empno = req.query.empno;
    let emp =undefined;
    for(let i=0;i<json.length;i++){
        if(json[i].empno == empno){
            emp = json[i];
            break;
        }
    }
    if(emp==undefined){
        res.send('can not get!!!!!')
    }else{
        res.render('queryone',{emps:emp});
    }
});

app.get('/employee/getone1/:empno',(req,res)=>{
    let empno = req.params.empno;
    let emp =undefined;
    for(let i=0;i<json.length;i++){
        if(json[i].empno == empno){
            emp = json[i];
            break;
        }
    }
    if(emp==undefined){
        res.send('can not get!!!!!');
    }else{
        res.send(emp);
    }
});

app.get('/employee/addnewdata',(req ,res) =>{
    let data =  req.query.empno+","+
                req.query.ename+","+
                req.query.hiredate+","+
                req.query.salary+","+
                req.query.deptno+","+
                req.query.title;
    fs.appendFile('employee.csv',"\n"+data,(err) =>{
            if (err) throw err;
            console.log('appended!!');
        });
});

app.get('/employee/find',(req,res) =>{
    let i =req.params.clickedElement.id;
    console.log(i);
    res.send(json[1]);
});

app.get('/employee/delete',(req,res) =>{
    let empno = req.query.empno;
    let filteredData = json.filter(item => item.empno !== empno);

    const fields = ['empno', 'ename', 'hiredate','salary','deptno','title'];

    const json2csvParser = new Parser({ fields });

    const csv = json2csvParser.parse(filteredData);

    fs.writeFile('data.csv', csv, (err) => {
      if (err) {
    console.error('Error writing CSV file:', err);
    } else {
    console.log('CSV file has been saved.');
     }
    });

});


app.get('/employee/change',(req,res) =>{
    let empno = req.query.empno;
    let filteredData = json.filter(item => item.empno !== empno);

    const fields = ['empno', 'ename', 'hiredate','salary','deptno','title'];

    const json2csvParser = new Parser({ fields });

    const csv = json2csvParser.parse(filteredData);

    fs.writeFile('data.csv', csv, (err) => {
      if (err) {
    console.error('Error writing CSV file:', err);
    } else {
    console.log('CSV file has been saved.');
     }
    });

});