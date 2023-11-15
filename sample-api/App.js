import axios from 'axios'
axios.get("https://randomuser.me/api/")
.then(response => console.log(response.data))
.catch(err => console.log(err));