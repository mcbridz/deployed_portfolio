document.addEventListener('DOMContentLoaded', function () {
    //sidenav init
    var elems = document.querySelectorAll('.sidenav')
    var instances = M.Sidenav.init(elems, {})
    //dropdown init
    // var drops = document.querySelectorAll('.dropdown-content')
    // var drops_option = {
    //     'closeOnClick': true,
    //     'hover': false,
    // }
    // var drops_instances = M.Dropdown.init(drops, drops_option)
    var drop_elems = document.querySelectorAll('.dropdown-trigger')
    var drop_instances = M.Dropdown.init(drop_elems, {})
})