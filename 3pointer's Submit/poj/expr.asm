
a.out：     文件格式 elf64-x86-64


Disassembly of section .init:

00000000004003e0 <_init>:
  4003e0:	48 83 ec 08          	sub    $0x8,%rsp
  4003e4:	48 8b 05 0d 0c 20 00 	mov    0x200c0d(%rip),%rax        # 600ff8 <_DYNAMIC+0x1d0>
  4003eb:	48 85 c0             	test   %rax,%rax
  4003ee:	74 05                	je     4003f5 <_init+0x15>
  4003f0:	e8 3b 00 00 00       	callq  400430 <__gmon_start__@plt>
  4003f5:	48 83 c4 08          	add    $0x8,%rsp
  4003f9:	c3                   	retq   

Disassembly of section .plt:

0000000000400400 <printf@plt-0x10>:
  400400:	ff 35 02 0c 20 00    	pushq  0x200c02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400406:	ff 25 04 0c 20 00    	jmpq   *0x200c04(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40040c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400410 <printf@plt>:
  400410:	ff 25 02 0c 20 00    	jmpq   *0x200c02(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400416:	68 00 00 00 00       	pushq  $0x0
  40041b:	e9 e0 ff ff ff       	jmpq   400400 <_init+0x20>

0000000000400420 <__libc_start_main@plt>:
  400420:	ff 25 fa 0b 20 00    	jmpq   *0x200bfa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400426:	68 01 00 00 00       	pushq  $0x1
  40042b:	e9 d0 ff ff ff       	jmpq   400400 <_init+0x20>

0000000000400430 <__gmon_start__@plt>:
  400430:	ff 25 f2 0b 20 00    	jmpq   *0x200bf2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400436:	68 02 00 00 00       	pushq  $0x2
  40043b:	e9 c0 ff ff ff       	jmpq   400400 <_init+0x20>

Disassembly of section .text:

0000000000400440 <_start>:
  400440:	31 ed                	xor    %ebp,%ebp
  400442:	49 89 d1             	mov    %rdx,%r9
  400445:	5e                   	pop    %rsi
  400446:	48 89 e2             	mov    %rsp,%rdx
  400449:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40044d:	50                   	push   %rax
  40044e:	54                   	push   %rsp
  40044f:	49 c7 c0 e0 05 40 00 	mov    $0x4005e0,%r8
  400456:	48 c7 c1 70 05 40 00 	mov    $0x400570,%rcx
  40045d:	48 c7 c7 43 05 40 00 	mov    $0x400543,%rdi
  400464:	e8 b7 ff ff ff       	callq  400420 <__libc_start_main@plt>
  400469:	f4                   	hlt    
  40046a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400470 <deregister_tm_clones>:
  400470:	b8 47 10 60 00       	mov    $0x601047,%eax
  400475:	55                   	push   %rbp
  400476:	48 2d 40 10 60 00    	sub    $0x601040,%rax
  40047c:	48 83 f8 0e          	cmp    $0xe,%rax
  400480:	48 89 e5             	mov    %rsp,%rbp
  400483:	77 02                	ja     400487 <deregister_tm_clones+0x17>
  400485:	5d                   	pop    %rbp
  400486:	c3                   	retq   
  400487:	b8 00 00 00 00       	mov    $0x0,%eax
  40048c:	48 85 c0             	test   %rax,%rax
  40048f:	74 f4                	je     400485 <deregister_tm_clones+0x15>
  400491:	5d                   	pop    %rbp
  400492:	bf 40 10 60 00       	mov    $0x601040,%edi
  400497:	ff e0                	jmpq   *%rax
  400499:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004a0 <register_tm_clones>:
  4004a0:	b8 40 10 60 00       	mov    $0x601040,%eax
  4004a5:	55                   	push   %rbp
  4004a6:	48 2d 40 10 60 00    	sub    $0x601040,%rax
  4004ac:	48 c1 f8 03          	sar    $0x3,%rax
  4004b0:	48 89 e5             	mov    %rsp,%rbp
  4004b3:	48 89 c2             	mov    %rax,%rdx
  4004b6:	48 c1 ea 3f          	shr    $0x3f,%rdx
  4004ba:	48 01 d0             	add    %rdx,%rax
  4004bd:	48 d1 f8             	sar    %rax
  4004c0:	75 02                	jne    4004c4 <register_tm_clones+0x24>
  4004c2:	5d                   	pop    %rbp
  4004c3:	c3                   	retq   
  4004c4:	ba 00 00 00 00       	mov    $0x0,%edx
  4004c9:	48 85 d2             	test   %rdx,%rdx
  4004cc:	74 f4                	je     4004c2 <register_tm_clones+0x22>
  4004ce:	5d                   	pop    %rbp
  4004cf:	48 89 c6             	mov    %rax,%rsi
  4004d2:	bf 40 10 60 00       	mov    $0x601040,%edi
  4004d7:	ff e2                	jmpq   *%rdx
  4004d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000004004e0 <__do_global_dtors_aux>:
  4004e0:	80 3d 59 0b 20 00 00 	cmpb   $0x0,0x200b59(%rip)        # 601040 <__TMC_END__>
  4004e7:	75 11                	jne    4004fa <__do_global_dtors_aux+0x1a>
  4004e9:	55                   	push   %rbp
  4004ea:	48 89 e5             	mov    %rsp,%rbp
  4004ed:	e8 7e ff ff ff       	callq  400470 <deregister_tm_clones>
  4004f2:	5d                   	pop    %rbp
  4004f3:	c6 05 46 0b 20 00 01 	movb   $0x1,0x200b46(%rip)        # 601040 <__TMC_END__>
  4004fa:	f3 c3                	repz retq 
  4004fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400500 <frame_dummy>:
  400500:	48 83 3d 18 09 20 00 	cmpq   $0x0,0x200918(%rip)        # 600e20 <__JCR_END__>
  400507:	00 
  400508:	74 1e                	je     400528 <frame_dummy+0x28>
  40050a:	b8 00 00 00 00       	mov    $0x0,%eax
  40050f:	48 85 c0             	test   %rax,%rax
  400512:	74 14                	je     400528 <frame_dummy+0x28>
  400514:	55                   	push   %rbp
  400515:	bf 20 0e 60 00       	mov    $0x600e20,%edi
  40051a:	48 89 e5             	mov    %rsp,%rbp
  40051d:	ff d0                	callq  *%rax
  40051f:	5d                   	pop    %rbp
  400520:	e9 7b ff ff ff       	jmpq   4004a0 <register_tm_clones>
  400525:	0f 1f 00             	nopl   (%rax)
  400528:	e9 73 ff ff ff       	jmpq   4004a0 <register_tm_clones>

000000000040052d <fun>:
  40052d:	55                   	push   %rbp
  40052e:	48 89 e5             	mov    %rsp,%rbp
  400531:	bf f4 05 40 00       	mov    $0x4005f4,%edi
  400536:	b8 00 00 00 00       	mov    $0x0,%eax
  40053b:	e8 d0 fe ff ff       	callq  400410 <printf@plt>
  400540:	90                   	nop
  400541:	5d                   	pop    %rbp
  400542:	c3                   	retq   

0000000000400543 <main>:
  400543:	55                   	push   %rbp
  400544:	48 89 e5             	mov    %rsp,%rbp
  400547:	bf f8 05 40 00       	mov    $0x4005f8,%edi
  40054c:	b8 00 00 00 00       	mov    $0x0,%eax
  400551:	e8 ba fe ff ff       	callq  400410 <printf@plt>
  400556:	b8 00 00 00 00       	mov    $0x0,%eax
  40055b:	e8 cd ff ff ff       	callq  40052d <fun>
  400560:	b8 00 00 00 00       	mov    $0x0,%eax
  400565:	5d                   	pop    %rbp
  400566:	c3                   	retq   
  400567:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40056e:	00 00 

0000000000400570 <__libc_csu_init>:
  400570:	41 57                	push   %r15
  400572:	41 89 ff             	mov    %edi,%r15d
  400575:	41 56                	push   %r14
  400577:	49 89 f6             	mov    %rsi,%r14
  40057a:	41 55                	push   %r13
  40057c:	49 89 d5             	mov    %rdx,%r13
  40057f:	41 54                	push   %r12
  400581:	4c 8d 25 88 08 20 00 	lea    0x200888(%rip),%r12        # 600e10 <__frame_dummy_init_array_entry>
  400588:	55                   	push   %rbp
  400589:	48 8d 2d 88 08 20 00 	lea    0x200888(%rip),%rbp        # 600e18 <__init_array_end>
  400590:	53                   	push   %rbx
  400591:	4c 29 e5             	sub    %r12,%rbp
  400594:	31 db                	xor    %ebx,%ebx
  400596:	48 c1 fd 03          	sar    $0x3,%rbp
  40059a:	48 83 ec 08          	sub    $0x8,%rsp
  40059e:	e8 3d fe ff ff       	callq  4003e0 <_init>
  4005a3:	48 85 ed             	test   %rbp,%rbp
  4005a6:	74 1e                	je     4005c6 <__libc_csu_init+0x56>
  4005a8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4005af:	00 
  4005b0:	4c 89 ea             	mov    %r13,%rdx
  4005b3:	4c 89 f6             	mov    %r14,%rsi
  4005b6:	44 89 ff             	mov    %r15d,%edi
  4005b9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4005bd:	48 83 c3 01          	add    $0x1,%rbx
  4005c1:	48 39 eb             	cmp    %rbp,%rbx
  4005c4:	75 ea                	jne    4005b0 <__libc_csu_init+0x40>
  4005c6:	48 83 c4 08          	add    $0x8,%rsp
  4005ca:	5b                   	pop    %rbx
  4005cb:	5d                   	pop    %rbp
  4005cc:	41 5c                	pop    %r12
  4005ce:	41 5d                	pop    %r13
  4005d0:	41 5e                	pop    %r14
  4005d2:	41 5f                	pop    %r15
  4005d4:	c3                   	retq   
  4005d5:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  4005dc:	00 00 00 00 

00000000004005e0 <__libc_csu_fini>:
  4005e0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004005e4 <_fini>:
  4005e4:	48 83 ec 08          	sub    $0x8,%rsp
  4005e8:	48 83 c4 08          	add    $0x8,%rsp
  4005ec:	c3                   	retq   
Contents of the .eh_frame section:

00000000 0000000000000014 00000000 CIE
  Version:               1
  Augmentation:          "zR"
  Code alignment factor: 1
  Data alignment factor: -8
  Return address column: 16
  Augmentation data:     1b

  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_offset: r16 (rip) at cfa-8
  DW_CFA_undefined: r16 (rip)

00000018 0000000000000014 0000001c FDE cie=00000000 pc=fffffffffffffdf8..fffffffffffffe22
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000030 0000000000000014 00000000 CIE
  Version:               1
  Augmentation:          "zR"
  Code alignment factor: 1
  Data alignment factor: -8
  Return address column: 16
  Augmentation data:     1b

  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_offset: r16 (rip) at cfa-8
  DW_CFA_nop
  DW_CFA_nop

00000048 0000000000000024 0000001c FDE cie=00000030 pc=fffffffffffffdb8..fffffffffffffdf8
  DW_CFA_def_cfa_offset: 16
  DW_CFA_advance_loc: 6 to fffffffffffffdbe
  DW_CFA_def_cfa_offset: 24
  DW_CFA_advance_loc: 10 to fffffffffffffdc8
  DW_CFA_def_cfa_expression (DW_OP_breg7 (rsp): 8; DW_OP_breg16 (rip): 0; DW_OP_lit15; DW_OP_and; DW_OP_lit11; DW_OP_ge; DW_OP_lit3; DW_OP_shl; DW_OP_plus)
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000070 000000000000001c 00000044 FDE cie=00000030 pc=fffffffffffffee5..fffffffffffffefb
  DW_CFA_advance_loc: 1 to fffffffffffffee6
  DW_CFA_def_cfa_offset: 16
  DW_CFA_offset: r6 (rbp) at cfa-16
  DW_CFA_advance_loc: 3 to fffffffffffffee9
  DW_CFA_def_cfa_register: r6 (rbp)
  DW_CFA_advance_loc: 17 to fffffffffffffefa
  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000090 000000000000001c 00000064 FDE cie=00000030 pc=fffffffffffffefb..ffffffffffffff1f
  DW_CFA_advance_loc: 1 to fffffffffffffefc
  DW_CFA_def_cfa_offset: 16
  DW_CFA_offset: r6 (rbp) at cfa-16
  DW_CFA_advance_loc: 3 to fffffffffffffeff
  DW_CFA_def_cfa_register: r6 (rbp)
  DW_CFA_advance_loc: 31 to ffffffffffffff1e
  DW_CFA_def_cfa: r7 (rsp) ofs 8
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

000000b0 0000000000000044 00000084 FDE cie=00000030 pc=ffffffffffffff28..ffffffffffffff8d
  DW_CFA_advance_loc: 2 to ffffffffffffff2a
  DW_CFA_def_cfa_offset: 16
  DW_CFA_offset: r15 (r15) at cfa-16
  DW_CFA_advance_loc: 5 to ffffffffffffff2f
  DW_CFA_def_cfa_offset: 24
  DW_CFA_offset: r14 (r14) at cfa-24
  DW_CFA_advance_loc: 5 to ffffffffffffff34
  DW_CFA_def_cfa_offset: 32
  DW_CFA_offset: r13 (r13) at cfa-32
  DW_CFA_advance_loc: 5 to ffffffffffffff39
  DW_CFA_def_cfa_offset: 40
  DW_CFA_offset: r12 (r12) at cfa-40
  DW_CFA_advance_loc: 8 to ffffffffffffff41
  DW_CFA_def_cfa_offset: 48
  DW_CFA_offset: r6 (rbp) at cfa-48
  DW_CFA_advance_loc: 8 to ffffffffffffff49
  DW_CFA_def_cfa_offset: 56
  DW_CFA_offset: r3 (rbx) at cfa-56
  DW_CFA_advance_loc: 13 to ffffffffffffff56
  DW_CFA_def_cfa_offset: 64
  DW_CFA_advance_loc: 44 to ffffffffffffff82
  DW_CFA_def_cfa_offset: 56
  DW_CFA_advance_loc: 1 to ffffffffffffff83
  DW_CFA_def_cfa_offset: 48
  DW_CFA_advance_loc: 1 to ffffffffffffff84
  DW_CFA_def_cfa_offset: 40
  DW_CFA_advance_loc: 2 to ffffffffffffff86
  DW_CFA_def_cfa_offset: 32
  DW_CFA_advance_loc: 2 to ffffffffffffff88
  DW_CFA_def_cfa_offset: 24
  DW_CFA_advance_loc: 2 to ffffffffffffff8a
  DW_CFA_def_cfa_offset: 16
  DW_CFA_advance_loc: 2 to ffffffffffffff8c
  DW_CFA_def_cfa_offset: 8
  DW_CFA_nop

000000f8 0000000000000014 000000cc FDE cie=00000030 pc=ffffffffffffff98..ffffffffffffff9a
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop
  DW_CFA_nop

00000110 ZERO terminator

